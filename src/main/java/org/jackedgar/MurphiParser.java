package org.jackedgar;

import java.util.*;

public class MurphiParser {
    /**
     * @param litmusMap                 The map containing the data from the JSON litmus test
     * @param threadSize                Map from a thread index to the number of instructions in the thread (to be filled)
     * @param stringAddressToIntAddress Map from address in JSON to integer address (to be filled)
     * @param protocol                  The name of the protocol that we are integrating into
     * @return Transpiled data for final Murphi file
     */
    protected static String[] parseLitmusToMurphi(Map<String, Object> litmusMap, Map<Integer, Integer> threadSize, Map<String, Integer> stringAddressToIntAddress,
                                                  String protocol) {

        // Get the maps that represent the processes and invariant
        List<Map<String, Object>> processes = (List<Map<String, Object>>) litmusMap.get("processes");
        List<Map<String, Object>> invariantMap = (List<Map<String, Object>>) litmusMap.get("invariant");

        // Initialize data structures that are useful when performing parsing, or that may need to be returned
        int nextFreeIntAddress = 0;
        int maxValue = 0;
        int maxRegs = 0;

        Set<Integer>[] regsInProcesses = new Set[processes.size()];

        StringBuilder litmusInitialization = new StringBuilder();
        StringBuilder threadDefinitions = new StringBuilder();
        StringBuilder invariant = new StringBuilder();

        // Begin the transpilation by iterating over each process
        for (int procId = 0; procId < processes.size(); procId++) {

            // Get the current process, collect metadata about its size, and get the list of instructions
            Map<String, Object> currentProcess = processes.get(procId);
            List<Object> instructions = (List<Object>) currentProcess.get("instructions");
            threadSize.put(procId, instructions.size());
            Set<Integer> regsInCurrentProcess = new HashSet<>();

            // Iterate over each instruction
            for (int instrId = 0; instrId < instructions.size(); instrId++) {

                // Convert each instruction to a map object
                Map<String, Object> currentInstruction = (Map<String, Object>) instructions.get(instrId);
                if (procId != 0 || instrId != 0) litmusInitialization.append("      ");

                // If the current instruction is a load, update the set of registers for that process
                if (currentInstruction.get("type").equals("load")) {
                    regsInCurrentProcess.add(Integer.parseInt(currentInstruction.get("value").toString()));
                }

                // Update the maximum value, so we should end up with the maximum used across all processes
                maxValue = Math.max((int) currentInstruction.get("value"), maxValue);

                // Append some thread initialization to the relevant string
                litmusInitialization.append("i_thread").append(procId + 1).append("[").append(instrId).append("].itype:=").append(currentInstruction.get("type")).append(";\n");
                litmusInitialization.append("      i_thread").append(procId + 1).append("[").append(instrId).append("].val:=").append(currentInstruction.get("value")).append(";\n");

                // If the mpa between string to integer addresses doesn't contain the current one, add it
                if (!stringAddressToIntAddress.containsKey(currentInstruction.get("address"))) {
                    stringAddressToIntAddress.put((String) currentInstruction.get("address"), nextFreeIntAddress);
                    nextFreeIntAddress++;
                }

                // Continue to generate the initialization string
                litmusInitialization.append("      i_thread").append(procId + 1).append("[").append(instrId).append("].adr:=").append(stringAddressToIntAddress.get(currentInstruction.get("address"))).append(";\n");
            }

            // Update the maximum regs variable, which should result in the maximum number of registers used in any
            // given process
            maxRegs = Math.max(maxRegs, regsInCurrentProcess.size());
            regsInProcesses[procId] = regsInCurrentProcess;

            litmusInitialization.append("\n");
        }

        // Iterate over each process again, appending data to both the thread definitions, and intitialization strings
        for (int procId = 0; procId < processes.size(); procId++) {
            litmusInitialization.append("      i_thread").append(procId + 1).append("[").append(threadSize.get(procId)).append("].adr:= 0;\n");
            if (procId != 0) threadDefinitions.append("      ");
            threadDefinitions.append("i_thread").append(procId + 1).append(": thread;\n");
        }

        litmusInitialization.append("\n");
        litmusInitialization.append("      initializer:= 0;\n" + "      instructionsExecuted:= 0;\n" + "\n" + "      for m:OBJSET_cacheL1C1 do\n" + "        i_threadMetadata[m].currentIndex:= 0;\n");


        for (int procId = 0; procId <= processes.size(); procId++) {
            if (procId == 0) litmusInitialization.append("        if initializer = ").append(procId).append(" then \n");
            else litmusInitialization.append("        elsif initializer = ").append(procId).append(" then \n");

            if (procId < processes.size()) {
                litmusInitialization.append("          i_threadMetadata[m].maxIndex:= ").append(threadSize.get(procId) - 1)
                        .append(";\n").append("          i_threadlist[m]:= i_thread").append(procId + 1).append(";\n").append("          initializer:= initializer + 1;\n");
                litmusInitialization.append("          i_threadScalarsetMapping[").append(procId).append("]:= m;\n");

                for (int k = 0; k < regsInProcesses[procId].size(); k++) {
                    litmusInitialization.append("          i_threadMetadata[m].regs[").append(k).append("] := 0;\n");
                }
            } else
                litmusInitialization.append("          i_threadMetadata[m].maxIndex:= 1;\n" + "          i_threadMetadata[m].currentIndex:= 2;\n").append("          i_threadScalarsetMapping[").append(procId).append("]:= m;\n");
        }

        litmusInitialization.append("        endif;\n" + "      endfor;");

        // Iterate over the invariant map (excluding the first, which is the boolean not function)
        for (int invariantId = 1; invariantId < invariantMap.size(); invariantId++) {

            // Get the current invariant, and iterate over all addresses
            Map<String, Object> currentInvariant = invariantMap.get(invariantId);
            for (String addr : stringAddressToIntAddress.keySet()) {

                // If the current invariant contains a key correlating to an address, then add that to the Murphi
                if (currentInvariant.containsKey(addr)) {

                    // This is for the MSI protocol
                    invariant.append("        (i_cacheL1C1[m].cb[").append(stringAddressToIntAddress.get(addr))
                            .append("].State = cacheL1C1_S | i_cacheL1C1[m].cb[").append(stringAddressToIntAddress.get(addr)).append("].State = cacheL1C1_M");

                    // This is an additional condition we must add if using the MESI protocol, allowing the E state
                    if (protocol.equalsIgnoreCase("mesi"))
                        invariant.append(" | i_cacheL1C1[m].cb[").append(stringAddressToIntAddress.get(addr)).append("].State = cacheL1C1_E");

                    invariant.append(") &\n");
                }
            }
        }

        // Add inversion of the invariant if necessary
        boolean invertInvariant = (boolean) invariantMap.get(0).get("not");
        if (!invertInvariant) invariant.append("!");
        invariant.append("(");

        // Iterate over the invariant again
        for (int i = 1; i < invariantMap.size(); i++) {
            Map<String, Object> currentInvariant = invariantMap.get(i);

            invariant.append("(");

            // Add any invariants on global addresses
            for (String addr : stringAddressToIntAddress.keySet()) {
                if (currentInvariant.containsKey(addr)) {
                    invariant.append("i_cacheL1C1[m].cb[").append(stringAddressToIntAddress.get(addr)).append("].cl = ").append(currentInvariant.get(addr)).append(" & ");
                }
            }

            invariant.append("(");

            // Collect a list of the threads that exist in the current invariant
            List<String> threadsInCurrentInvariant = new LinkedList<>();
            for (int threadId = 0; threadId < processes.size(); threadId++) {
                String threadIdString = String.valueOf(threadId);
                if (currentInvariant.containsKey(threadIdString)) threadsInCurrentInvariant.add(threadIdString);
            }

            // Iterate over those threads that exist within the current invariant
            for (int k = 0; k < threadsInCurrentInvariant.size(); k++) {

                // Get the current thread, the invariants on the registers for that thread
                String threadIdString = threadsInCurrentInvariant.get(k);
                Map<String, List<Integer>> currentThreadRegsToCheck = (Map<String, List<Integer>>) currentInvariant.get(threadIdString);

                // Iterate over each register in the thread
                for (String reg : currentThreadRegsToCheck.keySet()) {

                    // Get the allowed values for the registers
                    List<Integer> allowedListForReg = currentThreadRegsToCheck.get(reg);

                    for (int allowedIndex = 0; allowedIndex < allowedListForReg.size(); allowedIndex++) {
                        // Get the next allowed integer
                        int currentAllowed = allowedListForReg.get(allowedIndex);

                        // Append the restriction to the invariant
                        invariant.append("i_threadMetadata[i_threadScalarsetMapping[")
                                .append(threadIdString).append("]].regs[").append(reg).append("] = ").append(currentAllowed);

                        // Only perform logical OR if we aren't at the last allowed value
                        if (allowedIndex != allowedListForReg.size() - 1) invariant.append(" | ");
                    }

                    // If we aren't at the last register, use a logical AND
                    if (!Integer.valueOf(reg).equals(currentThreadRegsToCheck.size() - 1)) invariant.append(" & ");
                }

                // If we aren't at the last thread, append a logical AND
                if (k != threadsInCurrentInvariant.size() - 1) invariant.append(" & ");
            }

            invariant.append(")");

            invariant.append(")");
            if (i != invariantMap.size() - 1) invariant.append(" |\n");

        }

        invariant.append(") then \n             error \"Litmus test failed\" endif;\n");

        return new String[]{litmusInitialization.toString(), threadDefinitions.toString(), invariant.toString(),
                String.valueOf(maxValue), String.valueOf(maxRegs - 1)};
    }
}
