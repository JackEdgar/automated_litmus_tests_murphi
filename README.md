This tool provides automation for integrating litmus tests into Murphi-based cache coherence protocols.

The protocols themselves must take the form of a Murphi file that has been modified to allow template injection from Apache FreeMarker. Please see the included protocols in the templates folder as an example, and view the documentation for creating your own here:

https://freemarker.apache.org/docs/index.html

The litmus tests themselves have been represented as JSON files. Please see the litmus folder for examples. Note, the set of registers for each processor used must be sequentially ordered from zero (no gaps between integers). All currently included litmus tests are for Sequential Consistency (SC).

To execute the resultant Murphi files, use the following commands in your terminal, while in the output directory (with msi_r replaced with the test you have generated):

-> cmurphi-master/src/mu msi_r.m         

-> g++ msi_r.cpp -Icmurphi-master/include

-> ./a.out -tv -m512 -ndl

These are based on the precompiled Murphi compiler included in the output directory, but you are free to use your own. You may also increase the amount of RAM available by modifying the "-m512" command (which provides 512MB), which may be necessary for larger state spaces.

Bugged protocols have been included, which the user can integrate across the litmus test suite, and then execute each, which should ideally produce at least one failure.

Additional litmus tests can easily be added to the litmus folder, increasing test coverage, thereby strengthening the functionality and usefulness of the tool.
