package org.jackedgar;

import com.fasterxml.jackson.databind.ObjectMapper;
import freemarker.template.Configuration;
import freemarker.template.Template;
import freemarker.template.TemplateException;
import freemarker.template.TemplateExceptionHandler;

import java.io.*;
import java.nio.file.Paths;
import java.util.*;

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
     * @return A tree/map representation of our litmus test, that allows us to easily inject it into our template
     * @throws IOException Left this unchecked as not focusing on well-engineered code for this project
     */
    private static Map<String, Object> getLitmus(String litmusFilename, String templateFilename) throws IOException {

        // Useful data structures for completing the conversion
        ObjectMapper mapper = new ObjectMapper();
        Map<String, Integer> stringAddressToIntAddress = new HashMap<>();
        Map<Integer, Integer> threadSize = new HashMap<>();

        // Root of the object tree
        Map<String, Object> root = new HashMap<>();
        Map<String, Object> frameworkMap = new HashMap<>();

        // Reads the litmus test JSON into a map object (can think of this as a tree)
        Map<String, Object> litmusMap = mapper.readValue(Paths.get("litmus/"+ litmusFilename +".json").toFile(), Map.class);
        List<Map<String, Object>> processes = (List<Map<String, Object>>) litmusMap.get("processes");
        List<Map<String, Object>> invariant = (List<Map<String, Object>>) litmusMap.get("invariant");

        // Get the relevant strings in a legal Murphi representation
        Object[] murphi_strings = MurphiParser.parseLitmusToMurphi(processes, invariant, threadSize, stringAddressToIntAddress, templateFilename);

        // Calculate the total number of instructions (useful for knowing when to stop execution)
        int total_instruction_count = 0;
        for(Integer x : threadSize.values()) total_instruction_count += x;

        // Add all the Murphi converted data to the map, to allow for easy injection by FreeMarker
        frameworkMap.put("cache_count", processes.size());
        frameworkMap.put("total_instruction_count", total_instruction_count);
        frameworkMap.put("address_count", stringAddressToIntAddress.size());
        frameworkMap.put("litmus_initialization", murphi_strings[0]);
        frameworkMap.put("thread_declarations", murphi_strings[1]);
        frameworkMap.put("load_count", murphi_strings[2]);
        frameworkMap.put("cache_state_checks", murphi_strings[3]);
        root.put("LitmusFramework", frameworkMap);

        return root;
    }

    /**
     *
     * @param root The root of the litmus test, which will be the map object
     * @throws IOException Left this unchecked as not focusing on well-engineered code for this project
     * @throws TemplateException Left this unchecked as not focusing on well-engineered code for this project
     */
    public static void processProtocol(Map<String, Object> root, String templateFilename, String litmusFilename) throws IOException, TemplateException {
        Configuration cfg = getConfiguration();
        Template temp = cfg.getTemplate(templateFilename + ".m");
        Writer out = new BufferedWriter(new FileWriter("output/output_" + templateFilename + "_" + litmusFilename + ".m"));
        temp.process(root, out);
        out.close();

        System.out.println("\nPlease see output folder for your result. " +
                "Output requires Murphi compilation, followed by g++ compilation (if you wish to execute it).\n");
    }

    public static void main( String[] args ) throws TemplateException, IOException {
        // Get the litmus test they want
        BufferedReader reader = new BufferedReader(
                new InputStreamReader(System.in));
        System.out.println("Please enter the name of the litmus test you would like to use (excluding JSON file extension): ");
        String litmusFilename = reader.readLine();

        System.out.println("Please enter the protocol you would like to use (Currently accepted: msi, mesi): ");
        String templateFilename = reader.readLine();

        // Get the litmus test we want into a useful representation
        Map<String, Object> litmus_requested = getLitmus(litmusFilename, templateFilename);

        // Process the protocol file with the litmus test
        processProtocol(litmus_requested, templateFilename, litmusFilename);
    }
}
