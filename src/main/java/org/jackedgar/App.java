package org.jackedgar;

import com.fasterxml.jackson.databind.ObjectMapper;
import freemarker.template.Configuration;
import freemarker.template.Template;
import freemarker.template.TemplateException;
import freemarker.template.TemplateExceptionHandler;

import java.io.*;
import java.nio.file.Paths;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

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
        Map<String, Object> litmusMap = mapper.readValue(Paths.get("litmus/" + litmusFilename).toFile(), Map.class);

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
     * @param litmusToProcess The set of litmus tests to process
     * @param protocolsToProcess The set of protocols to process
     */
    private static void processProtocols(Set<String> litmusToProcess, Set<String> protocolsToProcess) throws IOException, TemplateException {

        for(String litmusFilename : litmusToProcess) {

            litmusFilename = litmusFilename.substring(0, litmusFilename.length() - 5);

            for(String templateFilename : protocolsToProcess) {
                // Get the requested litmus test into a map object, containing the relevant Murphi strings
                Map<String, Object> litmusMap = getLitmus(litmusFilename + ".json", templateFilename);

                // Get the requested cache coherence template into a template object
                Template cacheCoherenceTemplate = getConfiguration().getTemplate(templateFilename);

                templateFilename = templateFilename.substring(0, templateFilename.length() - 2);
                // Write the output to a new Murphi file
                Writer out = new BufferedWriter(new FileWriter("output/" + templateFilename + "_" + litmusFilename + ".m"));
                cacheCoherenceTemplate.process(litmusMap, out);
                out.close();
            }
        }

        System.out.println("\nPlease see output folder for your result. An executable version requires Murphi " +
                "compilation, followed by g++ compilation.\n");
    }

    /**
     * @param directory The directory we are targeting
     * @return A set of strings, containing all filenames in the requested directory
     */
    private static Set<String> getFileSet(String directory) {
        File[] files = new File(directory).listFiles();
        Set<String> filenames = new HashSet<>();

        for (File currentFile : files) filenames.add(currentFile.getName().toLowerCase());

        return filenames;
    }

    public static void main(String[] args) throws TemplateException, IOException {

        // Get the supported litmus tests and protocols
        Set<String> supportedLitmusTests = getFileSet("litmus");
        Set<String> supportedProtocols = getFileSet("templates");

        // Remove any Mac files that may be referenced in the folder
        supportedProtocols.remove(".ds_store");
        supportedLitmusTests.remove(".ds_store");

        // These will store the litmus test and protocols we want to process
        Set<String> litmusToProcess = new HashSet<>();
        Set<String> protocolsToProcess = new HashSet<>();

        // Get the requested litmus test and protocol
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String litmusFilename;
        String templateFilename;

        System.out.println("Please enter the name of the litmus test that you would like to use (excluding file extension) \n" +
                "or press enter to generate for all: ");
        while (true) {
            litmusFilename = reader.readLine();
            if (litmusFilename.equals("") | supportedLitmusTests.contains(litmusFilename.toLowerCase() + ".json")) break;
            System.out.println("Unsupported litmus test, please try again");
        }

        System.out.println("Please enter the protocol that you would like to use (excluding file extension) \n" +
                "or press enter to generate for all: ");
        while (true) {
            templateFilename = reader.readLine();
            if (templateFilename.equals("") | supportedProtocols.contains(templateFilename.toLowerCase() + ".m")) break;
            System.out.println("Unsupported protocol, please try again");
        }

        if(templateFilename.equals("")) protocolsToProcess = supportedProtocols;
        else protocolsToProcess.add(templateFilename + ".m");

        if(litmusFilename.equals("")) litmusToProcess = supportedLitmusTests;
        else litmusToProcess.add(litmusFilename + ".json");

        // Process the protocol, integrating the requested litmus test
        processProtocols(litmusToProcess, protocolsToProcess);
    }
}
