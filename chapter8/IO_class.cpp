// IO Library Headers
#include <iostream>
#include <fstream>
#include <sstream>

// IO Libraray Types
using std::istream;
using std::wistream;
using std::ostream;
using std::wostream;
using std::iostream;
using std::wiostream;
using std::ifstream;
using std::wifstream;
using std::ofstream;
using std::wofstream;
using std::fstream;
using std::wfstream;
using std::istringstream;
using std::wistringstream;
using std::ostringstream;
using std::wostringstream;
using std::stringstream;
using std::wstringstream;

// IO Library Objects
using std::cin;
using std::wcin;
using std::cout;
using std::wcout;
using std::cerr;
using std::wcerr;

// IO Library Manipulator
using std::endl;
using std::ends;
using std::flush;
using std::unitbuf;
using std::nounitbuf;


// IO Library Condition State
iostream::iostate state[4] = {iostream::badbit, iostream::failbit, iostream::eofbit, iostream::goodbit};


/*
 * Relationships among the IO Classes
 * 
 * The ifstream and istringstream inherits the istream, and so ofstream, ostringstream, ostream.
 * Everything that we cover in the section applies equally to plain streams, file streams, and string streams
 * and to the char or wide-character stream versions.
 * 
 * 
 * No copy or Assign for IO Objects
 * 
 * 
 * Condition States
 * 
 * Once an error has occured, subsequent IO operations on that steam will fail. We can read
 * from or write to a stream only when it is in a non-error state. The easiest way to
 * determine the state of a stream object is to use that obejct as a condition.
 *  
 * 
 * Interrogating the State of a Stream
 * 
 * The machine-dependent integral type named iostate is used to convey information about the 
 * state of a stream.
 * 
 * The badbit indicates a system-level failure; failbit is set after a recoverable error;
 * Reaching end-of-file sets both eofbit and failbit. The goodbit, which is guaranteed to 
 * have the value 0, indicates no failures on the stream. If any of badbit, failbit or eofbit
 * are set, then a condition that evaluates that stream will fail.
 * 
 * Indeed, the code that is executed when we use a stream as a condition is equivalent to
 * calling !fail().
 * 
 * 
 * Managing the Output Buffer
 * 
 * We can flush the buffer explicitly using a manipulator such as endl;
 * We can use the unitbuf manipulator to set the stream's internal state to empty the buffer
 * after each output operation. By default, unitbuf is set for cerr, so that writes to cerr
 * are flushed immediately.
 * 
 * An output stream might be tied to another stream. In this case, the buffer of the tying
 * stream is flushed whenever the tied stream is read or written. By default, cin and
 * cerr are both tied to cout. Hence, reading cin or writing cerr flushes the buffer in cout.
 * 
 * Except for the endl, there are two other similar manipulators: flush and ends. flush flushes
 * the stream but adds no characters to the output; ends inserts a null character into the buffer
 * and then flushes it.
 * 
 * 
 * The unitbuf Manipulator
 * 
 * 
 * Caution: Buffers Are Not Flushed If the Program Crashes
 * 
 * Countless hours of programmer time have been wasted tracking through code that appeared not
 * to have executed when in fact the buffer had not been flushed and the output was pending when
 * the program crashed.
 * 
 * 
 * Tying Input and Output Streams Together
 * 
 * There are two versions of tie member function. one takes no argument, returning a pointer to the ostream 
 * to which the object is tied or null pointer; another takes a pointer to ostream and ties itself
 * to that ostream. To untie the stream completely, we pass a null pointer. Each stream can be tied
 * to at most one stream at a time.
 */

void process_int(istream &is) {
    ;
}

int main(int argc, char const *argv[])
{

    cout.eof();
    cout.fail();
    cout.bad();
    cout.good();
    cout.clear();
    cout.clear(cout.badbit);
    cout.setstate(cout.eofbit);
    iostream::iostate state = cout.rdstate();


    auto old_state = cin.rdstate();
    cin.clear();
    process_int(cin);
    cin.setstate(old_state);

    // to turn off a single condition,  we use the rdstate member and the bitwise operations to 
    // produce the desired new state.
    
    // turns off falibit and badbit but all other bits unchanged
    cin.clear(cin.rdstate() & ~cin.badbit & ~cin.failbit);


    // flush manipulator
    cout << "This is a message!";
    cout << flush << ends << unitbuf << nounitbuf;

    // tying input and output stream together
    cin.tie(&cout);
    ostream *old_tie = cin.tie(nullptr);
    // ties cin to cerr
    cin.tie(&cerr);
    // change back
    cin.tie(old_tie);




    return 0;
}
