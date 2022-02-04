package org.jackedgar;

import com.fasterxml.jackson.databind.ObjectMapper;
import freemarker.template.Configuration;
import freemarker.template.Template;
import freemarker.template.TemplateException;
import freemarker.template.TemplateExceptionHandler;

import java.io.*;
import java.nio.file.Paths;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class App 
{
    /**
     *
     * @return FreeMarker configuration file
     * @throws IOException Left this unchecked as not focusing on well-engineered code for this project
     */
    private static Configuration getConfiguration() throws IOException {
        Configuration cfg = new Configuration(Configuration.VERSION_2_3_29);
        cfg.setDirectoryForTemplateLoading(new File("templates/"));
        cfg.setDefaultEncoding("UTF-8");
        cfg.setTemplateExceptionHandler(TemplateExceptionHandler.RETHROW_HANDLER);
        cfg.setLogTemplateExceptions(false);
        cfg.setWrapUncheckedExceptions(true);
        cfg.setFallbackOnNullLoopVariable(false);
        return cfg;
    }

    /**
     *
     * @param processes The list of processes/threads
     * @param threadSize Tracks the size of each thread (number of instructions in each)
     * @param stringAddressToIntAddress Converts between the string addresses, and a legal Murphi version (integer)
     * @return Litmus test declaration and initialization strings
     */
    private static String[] parseLitmusToMurphi(List<Map<String, Object>> processes, Map<Integer, Integer> threadSize,
                                                Map<String, Integer> stringAddressToIntAddress) {
        int nextFreeIntAddress = 0;
        String litmus_initialization_string = "";
        String thread_declarations_string = "";

        // Converts the instructions initialization into a Murphi representation
        for(int j = 0; j < processes.size(); j++) {
            Map<String, Object> currentProcess = processes.get(j);
            List<Object> instructions = (List<Object>) currentProcess.get("instructions");
            threadSize.put(j, instructions.size());

            for(int i = 0; i < instructions.size(); i++) {
                Map<String, Object> currentInstruction = (Map<String, Object>) instructions.get(i);
                litmus_initialization_string += "      i_thread" + (j+1) + "[" + i + "].itype:=" + currentInstruction.get("type") + ";\n";
                litmus_initialization_string += "      i_thread" + (j+1) + "[" + i + "].val:=" + currentInstruction.get("value") + ";\n";

                if(!stringAddressToIntAddress.containsKey(currentInstruction.get("address"))) {
                    stringAddressToIntAddress.put((String) currentInstruction.get("address"), nextFreeIntAddress);
                    nextFreeIntAddress++;
                }
                litmus_initialization_string += "      i_thread" + (j+1) + "[" + i + "].adr:=" + stringAddressToIntAddress.get(currentInstruction.get("address")) + ";\n";
            }
            litmus_initialization_string += "\n";
        }

        for(int j = 0; j < processes.size(); j++) {
            litmus_initialization_string += "      i_thread" + (j+1) + "[2].adr:= 0;\n";
            thread_declarations_string += "      i_thread" + (j+1) + ": thread;\n";
        }

        litmus_initialization_string += "\n";

        litmus_initialization_string += "      initializer:= 0;\n" +
                "      instructionsExecuted:= 0;\n" +
                "      loadedZeroCounter:= 0;\n" + "\n" + "      for m:OBJSET_cacheL1C1 do\n" +
                "        i_threadIndexes[m].currentIndex:= 0;\n";

        for(int i = 0; i <= processes.size(); i++) {
            if(i == 0) litmus_initialization_string += "        if initializer = " + i + " then \n";
            else litmus_initialization_string += "        elsif initializer = " + i + " then \n";

            if (i < processes.size()) litmus_initialization_string += "          i_threadIndexes[m].maxIndex:= " + (threadSize.get(i) - 1) + ";\n" +
                    "          i_threadlist[m]:= i_thread" + (i+1) + ";\n"
                    + "          initializer:= initializer + 1;\n";

            else litmus_initialization_string += "          i_threadIndexes[m].maxIndex:= 1;\n" +
                    "          i_threadIndexes[m].currentIndex:= 2;\n";
        }

        litmus_initialization_string += "        endif;\n" +
                "      endfor;";

        return new String[]{litmus_initialization_string, thread_declarations_string};
    }

    /**
     *
     * @return A tree/map representation of our litmus test, that allows us to easily inject it into our template
     * @throws IOException Left this unchecked as not focusing on well-engineered code for this project
     */
    private static Map<String, Object> getLitmus() throws IOException {

        // Useful data structures for completing the conversion
        ObjectMapper mapper = new ObjectMapper();
        Map<String, Integer> stringAddressToIntAddress = new HashMap<>();
        Map<Integer, Integer> threadSize = new HashMap<>();

        // Root of the object tree
        Map<String, Object> root = new HashMap<>();
        Map<String, Object> frameworkMap = new HashMap<>();

        // Get the litmus test they want
        BufferedReader reader = new BufferedReader(
                new InputStreamReader(System.in));
        System.out.println("Please enter the name of the litmus test you would like to use (excluding JSON file extension): ");
        String litmusFilename = reader.readLine();

        // Reads the litmus test JSON into a map object (can think of this as a tree)
        Map<String, Object> litmusMap = mapper.readValue(Paths.get("litmus/"+ litmusFilename +".json").toFile(), Map.class);
        List<Map<String, Object>> processes = (List<Map<String, Object>>) litmusMap.get("processes");

        // Get the relevant strings in a legal Murphi representation
        String[] murphi_strings = parseLitmusToMurphi(processes, threadSize, stringAddressToIntAddress);

        // Calculate the total number of instructions (useful for knowing when to stop execution)
        int total_instruction_count = 0;
        for(Integer x : threadSize.values()) total_instruction_count += x;

        // Add all the Murphi converted data to the map, to allow for easy injection by FreeMarker
        frameworkMap.put("cache_count", processes.size());
        frameworkMap.put("total_instruction_count", total_instruction_count);
        frameworkMap.put("address_count", stringAddressToIntAddress.size());
        frameworkMap.put("litmus_initialization", murphi_strings[0]);
        frameworkMap.put("thread_declarations", murphi_strings[1]);
        root.put("LitmusFramework", frameworkMap);

        return root;
    }

    /**
     *
     * @param root The root of the litmus test, which will be the map object
     * @throws IOException Left this unchecked as not focusing on well-engineered code for this project
     * @throws TemplateException Left this unchecked as not focusing on well-engineered code for this project
     */
    public static void processProtocol(Map<String, Object> root) throws IOException, TemplateException {
        Configuration cfg = getConfiguration();

        BufferedReader reader = new BufferedReader(
                new InputStreamReader(System.in));
        System.out.println("Please enter the protocol you would like to use (Currently accepted: msi): ");
        String templateFilename = reader.readLine();
        Template temp = cfg.getTemplate(templateFilename + ".m");
        Writer out = new BufferedWriter(new FileWriter("output/output_" + templateFilename + ".m"));
        temp.process(root, out);
        out.close();

        System.out.println("\nPlease see output folder for your result. " +
                "Output requires Murphi compilation, followed by g++ compilation (if you wish to execute it).\n");
    }

    public static void main( String[] args ) throws TemplateException, IOException {

        // Get the litmus test we want into a useful representation
        Map<String, Object> litmus_requested = getLitmus();

        // Process the protocol file with the litmus test
        processProtocol(litmus_requested);
    }
}
