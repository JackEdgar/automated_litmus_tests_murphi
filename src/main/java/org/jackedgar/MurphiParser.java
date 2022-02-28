package org.jackedgar;

import java.util.*;

public class MurphiParser {
    /**
     *
     * @param processes The list of processes from the JSON file
     * @param invariantMap The invariant from the JSON file
     * @param threadSize Map from a thread index to the number of instructions in the thread (to be filled)
     * @param stringAddressToIntAddress Map from address in JSON to integer address (to be filled)
     * @param protocol The name of the protocol that we are integrating into
     * @return Transpiled data for final Murphi file
     */
    protected static String[] parseLitmusToMurphi(List<Map<String, Object>> processes, List<Map<String, Object>> invariantMap,
                                                Map<Integer, Integer> threadSize, Map<String, Integer> stringAddressToIntAddress,
                                                String protocol) {
        // Initialize data structures that are useful when performing parsing, or that may need to be returned
        int nextFreeIntAddress = 0;
        int loadCount = 0;
        int maxValue = 0;

        int[] loadsInProcess = new int[processes.size()];
        List<Set<Integer>> regsInProcesses = new ArrayList<>();

        StringBuilder litmusInitialization = new StringBuilder();
        StringBuilder threadDefinitions = new StringBuilder();
        StringBuilder invariant = new StringBuilder();

        // Begin the transpilation at this point
        for(int j = 0; j < processes.size(); j++) {
            Map<String, Object> currentProcess = processes.get(j);
            List<Object> instructions = (List<Object>) currentProcess.get("instructions");
            threadSize.put(j, instructions.size());
            Set<Integer> regsInCurrentProcess = new HashSet<>();

            for(int i = 0; i < instructions.size(); i++) {
                Map<String, Object> currentInstruction = (Map<String, Object>) instructions.get(i);
                if(j != 0 || i != 0) litmusInitialization.append("      ");

                if(currentInstruction.get("type").equals("load")){
                    loadCount++;
                    loadsInProcess[j]++;
                    regsInCurrentProcess.add(Integer.parseInt(currentInstruction.get("value").toString()));
                }

                maxValue = Math.max((int) currentInstruction.get("value"), maxValue);

                litmusInitialization.append("i_thread").append(j + 1).append("[").append(i).append("].itype:=").append(currentInstruction.get("type")).append(";\n");
                litmusInitialization.append("      i_thread").append(j + 1).append("[").append(i).append("].val:=").append(currentInstruction.get("value")).append(";\n");

                if(!stringAddressToIntAddress.containsKey(currentInstruction.get("address"))) {
                    stringAddressToIntAddress.put((String) currentInstruction.get("address"), nextFreeIntAddress);
                    nextFreeIntAddress++;
                }
                litmusInitialization.append("      i_thread").append(j + 1).append("[").append(i).append("].adr:=").append(stringAddressToIntAddress.get(currentInstruction.get("address"))).append(";\n");
            }

            regsInProcesses.add(regsInCurrentProcess);

            litmusInitialization.append("\n");
        }

        for(int proc_id = 0; proc_id < processes.size(); proc_id++) {
            litmusInitialization.append("      i_thread").append(proc_id + 1).append("[").append(threadSize.get(proc_id)).append("].adr:= 0;\n");
            if(proc_id != 0) threadDefinitions.append("      ");
            threadDefinitions.append("i_thread").append(proc_id + 1).append(": thread;\n");
        }

        litmusInitialization.append("\n");

        litmusInitialization.append("      initializer:= 0;\n" + "      instructionsExecuted:= 0;\n" + "\n" + "      for m:OBJSET_cacheL1C1 do\n" + "        i_threadMetadata[m].currentIndex:= 0;\n");

        for(int i = 0; i <= processes.size(); i++) {
            if(i == 0) litmusInitialization.append("        if initializer = ").append(i).append(" then \n");
            else litmusInitialization.append("        elsif initializer = ").append(i).append(" then \n");

            if (i < processes.size()) {
                litmusInitialization.append("          i_threadMetadata[m].maxIndex:= ").append(threadSize.get(i) - 1)
                        .append(";\n").append("          i_threadlist[m]:= i_thread").append(i + 1).append(";\n").append("          initializer:= initializer + 1;\n");
                litmusInitialization.append("          i_threadScalarsetMapping[").append(i).append("]:= m;\n");

                for(int k = 0; k < regsInProcesses.get(i).size(); k++) {
                    litmusInitialization.append("          i_threadMetadata[m].regs[").append(k).append("] := 0;\n");
                }
            }

            else litmusInitialization.append("          i_threadMetadata[m].maxIndex:= 1;\n" + "          i_threadMetadata[m].currentIndex:= 2;\n").append("          i_threadScalarsetMapping[").append(i).append("]:= m;\n");
        }

        litmusInitialization.append("        endif;\n" + "      endfor;");

        for(int i = 1; i < invariantMap.size(); i++) {
            Map<String, Object> currentInvariant = invariantMap.get(i);
            for(String addr : stringAddressToIntAddress.keySet()) {
                if(currentInvariant.containsKey(addr)) {
                    invariant.append("        (i_cacheL1C1[m].cb[").append(stringAddressToIntAddress.get(addr))
                            .append("].State = cacheL1C1_S | i_cacheL1C1[m].cb[").append(stringAddressToIntAddress.get(addr)).append("].State = cacheL1C1_M");
                    if(protocol.equalsIgnoreCase("mesi")) invariant.append(" | i_cacheL1C1[m].cb[").append(stringAddressToIntAddress.get(addr)).append("].State = cacheL1C1_E");
                    invariant.append(") &\n");
                }
            }
        }

        boolean invertInvariant = (boolean) invariantMap.get(0).get("not");

        if(!invertInvariant) invariant.append("!");
        invariant.append("(");

        for(int i = 1; i < invariantMap.size(); i++) {
            Map<String, Object> currentInvariant = invariantMap.get(i);

            invariant.append("(");

            for(String addr : stringAddressToIntAddress.keySet()) {
                if(currentInvariant.containsKey(addr)) {
                    invariant.append("i_cacheL1C1[m].cb[").append(stringAddressToIntAddress.get(addr)).append("].cl = ").append(currentInvariant.get(addr)).append(" & ");
                }
            }

            invariant.append("(");

            List<String> threadsInCurrentInvariant = new LinkedList<>();
            for(int thread_id = 0; thread_id < processes.size(); thread_id++) {
                String thread_id_string = String.valueOf(thread_id);
                if(currentInvariant.containsKey(thread_id_string)) threadsInCurrentInvariant.add(thread_id_string);
            }

            for(int k = 0; k < threadsInCurrentInvariant.size(); k++) {
                String thread_id_string = threadsInCurrentInvariant.get(k);
                Map<String, List<Integer>> currentThreadRegsToCheck = (Map<String, List<Integer>>) currentInvariant.get(thread_id_string);

                for(String reg : currentThreadRegsToCheck.keySet()) {
                    List<Integer> allowedListForReg = currentThreadRegsToCheck.get(reg);

                    for(int a = 0; a < allowedListForReg.size(); a++) {
                        int currentAllowed = allowedListForReg.get(a);
                        invariant.append("i_threadMetadata[i_threadScalarsetMapping[")
                                .append(thread_id_string).append("]].regs[").append(reg).append("] = ").append(currentAllowed);
                        if(a != allowedListForReg.size() - 1) invariant.append(" | ");
                    }

                    if(!Integer.valueOf(reg).equals(currentThreadRegsToCheck.size() - 1)) invariant.append(" & ");
                }
                if(k != threadsInCurrentInvariant.size() - 1) invariant.append(" & ");
            }

            invariant.append(")");

            invariant.append(")");
            if(i != invariantMap.size() - 1) invariant.append(" |\n");

        }

        invariant.append(") then \n             error \"Litmus test failed\" endif;\n");

        return new String[]{litmusInitialization.toString(), threadDefinitions.toString(), String.valueOf(loadCount),
                invariant.toString(), String.valueOf(maxValue)};
    }
}
