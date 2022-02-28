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

public class App {
    /**
     * @return FreeMarker configuration file
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
     * @param litmusFilename   The name of the requested litmus test, excluding file extension
     * @param templateFilename The name of the requested template/protocol, excluding file extension
     * @return A tree/map representation of our litmus test, that allows us to easily inject it into our template
     */
    private static Map<String, Object> getLitmus(String litmusFilename, String templateFilename) throws IOException {

        // Mapper allow us to read the JSON file
        ObjectMapper mapper = new ObjectMapper();

        // These will contain useful metadata after processing
        Map<String, Integer> stringAddressToIntAddress = new HashMap<>();
        Map<Integer, Integer> threadSize = new HashMap<>();

        /* Create a root map, which will be the final result, along with a framework map, which will be the
           "LitmusFramework" object in the templates */
        Map<String, Object> root = new HashMap<>();
        Map<String, Object> frameworkMap = new HashMap<>();

        // Get the JSON litmus test as a map object, then extract the processes and invariant
        Map<String, Object> litmusMap = mapper.readValue(Paths.get("litmus/" + litmusFilename + ".json").toFile(), Map.class);
        List<Map<String, Object>> processes = (List<Map<String, Object>>) litmusMap.get("processes");
        List<Map<String, Object>> invariant = (List<Map<String, Object>>) litmusMap.get("invariant");

        // Parse the litmus test into Murphi, storing the results into a string array
        String[] murphiStrings = MurphiParser.parseLitmusToMurphi(processes, invariant, threadSize, stringAddressToIntAddress, templateFilename);

        // Calculate the total number of instructions across all threads/processors in the litmus test
        int totalInstructionCount = 0;
        for (Integer x : threadSize.values()) totalInstructionCount += x;

        // Add all relevant data to the map, for later injection by FreeMarker
        frameworkMap.put("cache_count", processes.size());
        frameworkMap.put("total_instruction_count", totalInstructionCount);
        frameworkMap.put("address_count", stringAddressToIntAddress.size());
        frameworkMap.put("litmus_initialization", murphiStrings[0]);
        frameworkMap.put("thread_declarations", murphiStrings[1]);
        frameworkMap.put("load_count", murphiStrings[2]);
        frameworkMap.put("cache_state_checks", murphiStrings[3]);
        frameworkMap.put("max_value", murphiStrings[4]);
        root.put("LitmusFramework", frameworkMap);

        return root;
    }

    /**
     * Processes the requested protocol, by integrating the requested litmus test, and outputting the resulting file
     *
     * @param templateFilename The name of the requested template/protocol, excluding file extension
     * @param litmusFilename   The name of the requested litmus test, excluding file extension
     */
    private static void processProtocol(String templateFilename, String litmusFilename) throws IOException, TemplateException {

        // Get the requested litmus test into a map object, containing the relevant Murphi strings
        Map<String, Object> litmusMap = getLitmus(litmusFilename, templateFilename);

        // Get the requested cache coherence template into a template object
        Template cacheCoherenceTemplate = getConfiguration().getTemplate(templateFilename + ".m");

        // Write the output to a new Murphi file
        Writer out = new BufferedWriter(new FileWriter("output/" + templateFilename + "_" + litmusFilename + ".m"));
        cacheCoherenceTemplate.process(litmusMap, out);
        out.close();

        System.out.println("\nPlease see output folder for your result. An executable version requires Murphi " +
                "compilation, followed by g++ compilation.\n");
    }

    public static void main(String[] args) throws TemplateException, IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Please enter the name of the litmus test that you would like to use (excluding file extension): ");
        String litmusFilename = reader.readLine();

        System.out.println("Please enter the protocol you would like to use (Currently accepted: msi, mesi): ");
        String templateFilename = reader.readLine();

        // Process the protocol, integrating the requested litmus test
        processProtocol(templateFilename, litmusFilename);
    }
}
