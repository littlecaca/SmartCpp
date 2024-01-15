#include <iostream>
#include <string>
#include <fstream>

// fstream-Specific Operations
using std::fstream;
using std::ofstream;
using std::ifstream;

/*
 * File Input and Output
 * 
 * 
 * Using an fstream in Place of an iostream &
 * 
 * Beacause inheriance, if we have a function that takes an ostream &, we can call that function
 * passing it an ofstream object, and similarly for istream & and ifstream.
 * 
 * 
 * The open and close Members
 * 
 * If a call to `open` fails, failbit is set. Because a call to open might fail, it is usually
 * a good idea to verify that open succeeded. Calling open on a file stream that is already open
 * will fail and set failbit. Once the file is closed, we can open a new one.
 * 
 * 
 * Automatic Construction and Destruction
 * 
 * When an fstream object is destroyed, close is called automatically.
 * 
 * 
 * File Modes
 * 
 * in   Open for input, only for ifstream and fstream
 * out  Open for output, only for ofstream and fstream
 * app  Seek to the end before every write, can be set as long as trunc is not.
 * ate  Seek to the end immediately after the open
 * trunc    Truncate the file, may be set only when out is also specified
 * binary   Do IO operations in binary mode
 * 
 * By default, a file opened in out mode is truncated even if we do not specify trunc.
 * 
 * The ate and binary modes may be specified on any file stream object type and in combination
 * with any other modes.
 * 
 * The only way to perserve the existing data in a file opened by an ofstream is to
 * specify app or in mode explicitly.
 */

int main(int argc, char const *argv[])
{
    /* code */
    fstream fs; // creates an unbound file stream.

    // these constructors are explicit. the default file mode depends on the type of fstream 
    fstream fs2("file1");   

    // fstream fs3("file2");

    ofstream out;
    out.open("file3");
    if (out) {
        // verify that open succeeded
    }
    
    
    return 0;
}
