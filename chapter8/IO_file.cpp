#include <iostream>
#include <string>
#include <fstream>

// fstream-Specific Operations
using std::fstream;


/*
 * File Input and Output
 * 
 * 
 */

int main(int argc, char const *argv[])
{
    /* code */
    fstream fs; // creates an unbound file stream.

    // these constructors are explicit. the default file mode depends on the type of fstream 
    fstream fs2("file1");   

    // fstream fs3("file2");
    return 0;
}
