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

    public static void main( String[] args ) throws TemplateException, IOException {

        Map<String, Integer> stringAddressToIntAddress = new HashMap<>();
        Map<Integer, Integer> threadSize = new HashMap<>();
        int nextFreeIntAddress = 0;

        // Setup the configuration
        Configuration cfg = getConfiguration();
        ObjectMapper mapper = new ObjectMapper();

        // Root of the object tree
        Map<String, Object> root = new HashMap<>();
        Map<String, Object> frameworkMap = new HashMap<>();

        Map<String, Object> litmusMap = mapper.readValue(Paths.get("litmus/litmus.json").toFile(), Map.class);

        List<Map<String, Object>> processes = (List<Map<String, Object>>) litmusMap.get("processes");

        String litmus_initialization_string = "";
        String thread_declarations_string = "";

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

        int total_instruction_count = 0;
        for(Integer x : threadSize.values()) total_instruction_count += x;

        frameworkMap.put("cache_count", processes.size());
        frameworkMap.put("total_instruction_count", total_instruction_count);
        frameworkMap.put("address_count", stringAddressToIntAddress.size());
        frameworkMap.put("thread_declarations", thread_declarations_string);
        frameworkMap.put("litmus_initialization", litmus_initialization_string);
        root.put("LitmusFramework", frameworkMap);

        // Get the requested template, and the MSI file

        BufferedReader reader = new BufferedReader(
                new InputStreamReader(System.in));
        System.out.println("Please enter the name of the template you would like to" +
                " load (must be in the templates folder, and exclude .m extension): ");
        String templateFilename = reader.readLine();
        Template temp = cfg.getTemplate(templateFilename + ".m");
        Writer out = new BufferedWriter(new FileWriter("output/output_" + templateFilename + ".m"));
        temp.process(root, out);

        out.close();
    }
}
