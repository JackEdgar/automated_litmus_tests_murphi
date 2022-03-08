This tool provides automation for integrating litmus tests into a Murphi-based cache coherence protocol.

The protocols themselves must take the form of a Murphi file that has been modified to allow template injection from Apache FreeMarker. Please see the included
"msi.m" file under the templates folder for an example, and view the documentation for creating your own here:

https://freemarker.apache.org/docs/index.html

The litmus tests themselves have been represented as JSON files. Please see the litmus folder for examples. The "name" field for each process/thread
is simply syntactic sugar, and is not necessary for the tool to function. Also note, the set of registers for each processor used must be sequentially ordered from zero (no gaps between integers). All currently included litmus tests are for Sequential Consistency (SC).

To run the output once generated, use the following commands in your terminal, while in the output directory (with msi_r replaced with the test you have generated):

-> cmurphi-master/src/mu msi_r.m         

-> g++ msi_r.cpp -Icmurphi-master/include

-> ./a.out -tv -m512

There is a precompiled Murphi compiler included in the output directory, but you are free to use your own. The flags on the last line provide certain
properties (tv provides a detailed trace, m512 provides the program with 512MB of RAM which can be adjusted as needed if you find too many active states).
