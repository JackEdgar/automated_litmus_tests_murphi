package org.jackedgar;

import com.fasterxml.jackson.databind.ObjectMapper;
import freemarker.template.Configuration;
import freemarker.template.Template;
import freemarker.template.TemplateException;
import freemarker.template.TemplateExceptionHandler;

import java.io.*;
import java.nio.file.Paths;
import java.util.HashMap;
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

        // Parse the litmus test into Murphi, storing the results into a string array
        String[] murphiStrings = MurphiParser.parseLitmusToMurphi(litmusMap, threadSize, stringAddressToIntAddress, templateFilename);

        // Calculate the total number of instructions and maximum possible index (across all threads)
        int maximumIndex = 1;
        int totalInstructionCount = 0;
        for (Integer x : threadSize.values()) {
            totalInstructionCount += x;
            maximumIndex = Math.max(maximumIndex, x);
        }
        maximumIndex -= 1;

        // Add all relevant data to the map, for later injection by FreeMarker
        frameworkMap.put("cache_count", threadSize.size());
        frameworkMap.put("total_instruction_count", totalInstructionCount);
        frameworkMap.put("max_thread_index", maximumIndex);
        frameworkMap.put("address_count", stringAddressToIntAddress.size());
        frameworkMap.put("litmus_initialization", murphiStrings[0]);
        frameworkMap.put("thread_definitions", murphiStrings[1]);
        frameworkMap.put("invariant", murphiStrings[2]);
        frameworkMap.put("max_value", murphiStrings[3]);
        frameworkMap.put("max_regs_index", murphiStrings[4]);
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
