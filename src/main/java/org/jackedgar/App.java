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
        }

        litmus_initialization_string += "\n";

        litmus_initialization_string += "      initializer:= 0;\n" +
                "      instructionsExecuted:= 0;\n" +
                "      loadedZeroCounter:= 0;\n" + "\n" + "      for m:OBJSET_cacheL1C1 do\n" +
                "        i_threadIndexes[m].currentIndex:= 0;\n";

        // need to parse initialization here
        litmus_initialization_string += "        if initializer = 0 then \n" +
                "          i_threadIndexes[m].maxIndex:= 1;\n" +
                "          i_threadlist[m]:= i_thread1;\n" +
                "          initializer:= initializer + 1;\n" +
                "        elsif initializer = 1 then\n" +
                "          i_threadIndexes[m].maxIndex:= 1;\n" +
                "          i_threadlist[m]:= i_thread2;\n" +
                "          initializer:= initializer + 1;\n" +
                "        elsif initializer = 2 then\n" +
                "          i_threadIndexes[m].maxIndex:= 1;\n" +
                "          i_threadIndexes[m].currentIndex:= 2;\n";

        litmus_initialization_string += "        endif;\n" +
                "      endfor;";

        frameworkMap.put("cache_count", litmusMap.get("cache_count"));
        frameworkMap.put("total_instruction_count", litmusMap.get("total_instruction_count"));
        frameworkMap.put("address_count", litmusMap.get("address_count"));

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
