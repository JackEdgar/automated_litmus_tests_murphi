This tool provides automation for integrating litmus tests into a Murphi-based cache coherence protocol.

The protocols themselves must take the form of a Murphi file that has been modified to allow template injection from Apache FreeMarker. Please see the included
"msi.m" file under the templates folder for an example, and view the documentation for creating your own here:

https://freemarker.apache.org/docs/index.html

The litmus tests themselves have been represented as JSON files. Please see the litmus folder for examples. (P.S. The "name" field for each process/thread
is simply syntactic sugar, and is not necessary for the tool to function).

To run the output once generated, use the following commands in your terminal, while in the output directory (with output_msi replaced with your output file):

-> cmurphi-master/src/mu output_msi.m         

-> g++ output_msi.cpp -Icmurphi-master/include

-> ./a.out -tv -m512 -ndl

This uses a precompiled Murphi compiler that is included in the output directory. You may however use your own. The flags on the last line provide certain
properties (tv provides a detailed trace, -m512 provides the program with 512MB of RAM which can be adjusted as needed if you find too many active states).
