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

    public static void main(String[] args) throws TemplateException, IOException {

        // Get the supported litmus tests and protocols
        Set<String> supportedLitmusTests = getFileSet("litmus");
        Set<String> supportedProtocols = getFileSet("templates");

        System.out.println("Enter the name of the targeted litmus test (excluding file extension), or press enter to generate for all:");
        Set<String> litmusToProcess = getFilesToProcess(supportedLitmusTests);

        System.out.println("Enter the name of the targeted protocol (excluding file extension), or press enter to generate for all: ");
        Set<String> protocolsToProcess = getFilesToProcess(supportedProtocols);

        // Process the protocols, integrating the requested litmus tests
        processProtocols(litmusToProcess, protocolsToProcess);
    }

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

        Map<String, Object> root = new HashMap<>();

        // Get the JSON litmus test as a map object
        Map<String, Object> litmusMap = mapper.readValue(Paths.get("litmus/" + litmusFilename).toFile(), Map.class);

        // Parse the litmus test into a valid map object for the protocol
        Map<String, Object> frameworkMap = MurphiParser.parseLitmusToMurphi(litmusMap, templateFilename);
        root.put("LitmusFramework", frameworkMap);

        return root;
    }

    /**
     * Processes the requested protocol, by integrating the requested litmus test, and outputting the resulting file
     *
     * @param litmusToProcess    The set of litmus tests to process
     * @param protocolsToProcess The set of protocols to process
     */
    private static void processProtocols(Set<String> litmusToProcess, Set<String> protocolsToProcess) throws IOException, TemplateException {

        for (String litmusFilename : litmusToProcess) {

            // Remove the JSON file extension from the litmus test filename
            litmusFilename = litmusFilename.substring(0, litmusFilename.length() - 5);

            for (String templateFilename : protocolsToProcess) {
                // Get the requested litmus test into a map object, containing the relevant Murphi strings
                Map<String, Object> litmusMap = getLitmus(litmusFilename + ".json", templateFilename);

                // Get the requested cache coherence template into a template object
                Template cacheCoherenceTemplate = getConfiguration().getTemplate(templateFilename);

                // Remove the Murphi file extension from the protocol filename
                templateFilename = templateFilename.substring(0, templateFilename.length() - 2);

                // Integrate the litmus test into the protocol framework, and produce it as an output
                Writer out = new BufferedWriter(new FileWriter("output/" + templateFilename + "_" + litmusFilename + ".m"));
                cacheCoherenceTemplate.process(litmusMap, out);
                out.close();
            }
        }

        System.out.println("\nPlease see output folder for your result. An executable version requires Murphi " +
                "compilation to C++, followed by C++ compilation.\n");
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

    /**
     * @param supportedFiles The set of files that are supported in the targeted directory
     * @return The set of files the user would like to process
     */
    public static Set<String> getFilesToProcess(Set<String> supportedFiles) throws IOException {

        Set<String> result = new HashSet<>();
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String requestedFile;

        // Remove any Mac files that may be referenced in the folder
        supportedFiles.remove(".ds_store");

        while (true) {
            requestedFile = reader.readLine();

            if (requestedFile.equals("")) {
                result = supportedFiles;
                break;
            } else if (supportedFiles.contains(requestedFile.toLowerCase() + ".json")) {
                result.add(requestedFile + ".json");
                break;
            } else if (supportedFiles.contains(requestedFile.toLowerCase() + ".m")) {
                result.add(requestedFile + ".m");
                break;
            }

            System.out.println("Unsupported, please try again.");
        }

        return result;
    }
}
