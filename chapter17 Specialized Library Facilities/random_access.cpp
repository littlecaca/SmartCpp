#include <fstream>
#include <string>
#include <iostream>

using namespace std;

/*
 * Warning
 * On windows, the MinGW's C++ platform counts the <CR><LF> as distinct characters on seek, but as a single on tell. 
 * Something along those lines. No easy solution - the least difficult workaround is probably 
 * to open the file in binary mode, and deal with (remove) the extra <CR> in the code. 
 *      --from  https://stackoverflow.com/questions/49377648/seekg-not-getting-the-correct-position-returned-by-tellg-on-windows-but-wor
 */



int main()
{
    // open for input and output and preposition file pointers to end-of-file
    // file mode argument see § 8.4 (p. 319)
    fstream inOut("copyOut.txt", fstream::ate | fstream::in |
                                 fstream::out | fstream::binary);
    if (!inOut)
    {
        cerr << "Unable to open file!" << endl;
        return EXIT_FAILURE; // EXIT_FAILURE see § 6.3.2 (p. 227)
    }
    // inOut is opened in ate mode, so it starts out positioned at the end
    auto end_mark = inOut.tellg(); // remember original end-of-file position
    inOut.seekg(0, fstream::beg);  // reposition to the start of the file
    size_t cnt = 0;                // accumulator for the byte count
    string line;                   // hold each line of input
    // while we haven't hit an error and are still reading the original data
    while (inOut && inOut.tellg() != end_mark && getline(inOut, line))
    {                                 // and can get another line of input
        cout << line << endl;
        cnt += line.size();       // add 1 to account for the newline
        auto mark = inOut.tellg();    // remember the read position
        inOut.seekp(0, fstream::end); // set the write marker to the end
        inOut << cnt;                 // write the accumulated length
        // print a separator if this is not the last line
        if (mark != end_mark)
            inOut << " ";
        inOut.seekg(mark); // restore the read position
    }
    inOut.seekp(0, fstream::end); // seek to the end
    inOut << "\n";                // write a newline at end-offile
    return 0;
}