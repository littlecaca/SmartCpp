#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;


/*
 * Format Input and Output
 * 
 * The library defines a set of manipulators (§ 1.2, p. 7), listed in Tables 17.17 (p.
 * 757) and 17.18 (p. 760), that modify the format state of a stream. A manipulator is a
 * function or object that affects the state of a stream and can be used as an operand to
 * an input or output operator.
 * 
 * Manipulators are used for two broad categories of output control: controlling the
 * presentation of numeric values and controlling the amount and placement of padding.
 * 
 * Warning
 * Manipulators that change the format state of the stream usually leave the
 * format state changed for all subsequent IO.
 * 
 * 
 * Controlling the Format of Floating-Point Values
 * 
 * By default, floating-point values are printed using six digits of precision; the decimal
 * point is omitted if the value has no fractional part; and they are printed in either fixed
 * decimal or scientific notation depending on the value of the number. The library
 * chooses a format that enhances readability of the number. Very large and very small
 * values are printed using scientific notation. Other values are printed in fixed decimal.
 * s
 * We can change the precision by calling the precision member of an IO object or
 * by using the setprecision manipulator. 
 * 
 * Note
 * The setprecision manipulators and other manipulators that take
 * arguments are defined in the iomanip header.
 * 
 * 
 * Best Practices
 * Unless you need to control the presentation of a floating-point number (e.g.,
 * to print data in columns or to print data that represents money or a
 * percentage), it is usually best to let the library choose the notation.
 * 
 * 
 * Specifying the Notation of Floating-Point Numbers
 * 
 * After executing scientific, fixed, or hexfloat, the precision value controls the
 * number of digits after the decimal point. By default, precision specifies the total
 * number of digits—both before and after the decimal point.
 * 
 * 
 * Padding the Output
 * 
 * • setw to specify the minimum space for the next numeric or string value.
 * • left to left-justify the output.
 * • right to right-justify the output. Output is right-justified by default.
 * • internal controls placement of the sign on negative values. internal leftjustifies the sign and right-justifies the value, padding any intervening space with
 *   blanks.
 * • setfill lets us specify an alternative character to use to pad the output. By
 *   default, the value is a space.
 * 
 * Note
 * setw, like endl, does not change the internal state of the output stream. It
 * determines the size of only the next output.
 * 
 * 
 * Manipulators Defined in iomanip
 * 
 * setfill(ch)
 * setprecision(n)
 * setw(w)
 * setbase(b)
 * 
 * 
 * 
 * Controlling Input Formatting
 * skipws
 * noskipws
 * 
 * 
 * 
 * Unformatted Input/Output Operations
 * 
 * Single-Byte Operations (All these return is/os, except is.get and is.peek)
 * 
 * is.get(ch)
 * os.put(ch)
 * is.get()     Return next byte from is as an int
 * is.pushback(ch)  The argument must be the same as the one that was last read.
 * is.unget()   Move `is` back one byte
 * is.peek()    Return the next byte as an `int` but doesn't remove it
 * 
 * 
 * Putting Back onto an Input Stream
 * int Return Values from Input Operations
 * The reason that these functions return an int is to allow them to return an end-offile marker.
 * 
 * The functions that return int convert the character they return to unsigned char
 * and then promote that value to int. As a result, even if the character set has
 * characters that map to negative values, the int returned from these operations will
 * be a positive value (§ 2.1.2, p. 35). The library uses a negative value to represent
 * end-of-file, which is thus guaranteed to be distinct from any legitimate character
 * value.
 * 
 * 
 * 
 * Multi-Byte Low-Level IO Operations
 * 
 * is.get(sink, size, delim)    If delim is present, it is left on the input stream and not read into sink.
 * is.getline(sink, size, delim)    Reads and discards delim
 * is.read(sink, size)
 * is.gcount()
 * os.write(source, size)
 * is.ignore(sizw, delim)
 * 
 * The difference between these functions is the treatment of the delimiter: get leaves
 * the delimiter as the next character of the istream, whereas getline reads and
 * discards the delimiter. In either case, the delimiter is not stored in sink.
 * 
 * Warning
 * It is a common error to intend to remove the delimiter from the stream but
 * to forget to do so.
 * 
 * It is essential to call gcount before any intervening unformatted input
 * operation. In particular, the single-character operations that put characters back on
 * the stream are also unformatted input operations. If peek, unget, or putback are
 * called before calling gcount, then the return value will be 0.
 * 
 * 
 * 
 * Random Access to a Stream
 * 
 * Note
 * Random IO is an inherently system-dependent. To understand how to use
 * these features, you must consult your system’s documentation.
 * 
 * On most systems, the streams bound to cin, cout, cerr, and clog do not support random
 * access. 
 * 
 * 
 * 
 * Caution: Low-Level Routines Are Error-Prone
 * 
 * The IO operations that return int are a good example of why.
 * 
 * 
 * 
 * Seek and Tell Functions
 * 
 * tellg()
 * tellp()
 * seekg()
 * seekp()
 * seekg(off, from)
 * seekg(off, from) `from` can be one of `beg`, `cur`, `end`
 * 
 * Logically enough, we can use only the g versions on an istream and on the types
 * ifstream and istringstream that inherit from istream (§ 8.1, p. 311). We can
 * use only the p versions on an ostream and on the types that inherit from it,
 * ofstream and ostringstream. An iostream, fstream, or stringstream can
 * both read and write the associated stream; we can use either the g or p versions on
 * objects of these types.
 * 
 * 
 * There Is Only One Marker
 * 
 * The fstream and stringstream types can read and write the same stream. In
 * these types there is a single buffer that holds data to be read and written and a single
 * marker denoting the current position in the buffer. The library maps both the g and p
 * positions to this single marker.
 * 
 * Note
 * Because there is only a single marker, we must do a seek to reposition the
 * marker whenever we switch between reading and writing.
 * 
 * 
 */

int main(int argc, char const *argv[])
{
    // Controlling the Format of Boolean Values
    cout << "default bool values: " << true << " " << false 
    << "\nalpha bool values: " << boolalpha << true << " " << false << endl;

    // Undo the format state change to cout
    cout << noboolalpha;

    // Specifying the Base for Integral Values
    cout << "default: " << 20 << " " << 1024 << endl;
    cout << "octal: " << oct << 20 << " " << 1024 << endl;
    cout << "hex: " << hex << 20 << " " << 1024 << endl;
    cout << "decimal: " << dec << 20 << " " << 1024 << endl;

    // Indicating Base on the Output
    cout << showbase; // show the base when printing integral values
    cout << "default: " << 20 << " " << 1024 << endl;
    cout << "in octal: " << oct << 20 << " " << 1024 << endl;
    cout << "in hex: " << hex << 20 << " " << 1024 << endl;
    cout << "in decimal: " << dec << 20 << " " << 1024 << endl;
    cout << noshowbase; // reset the state of the stream
    // Uppercase 
    cout << uppercase << showbase << hex << "printed in hexadecimal: " 
        << 20 << " " << 1024 << nouppercase << noshowbase << dec << endl;


    // Controlling the Format of Floating-Point Values

    // Specifying How Much Precision to Print
    // Precision controls the total number of digits that are printed.
    // When printed, floating-point values are rounded, not truncated, to the current precision.
    cout << "Default precision: " << cout.precision() << endl;
    cout << 3.1415926 << endl;
    cout.precision(5);
    cout << 3.1415926 << "\n\n";

    // Specifying the Notation of Floating-Point Numbers
    cout << "default format: " << 100 * sqrt(2.0) << '\n' 
        << "scientific: " << scientific << 100 * sqrt(2.0) << '\n'
        << "fixed decimal: " << fixed << 100 * sqrt(2.0) << '\n'
        << "hexadecimal: " << hexfloat << 100 * sqrt(2.0) << '\n'
        << "use defaults: " << defaultfloat << 100 * sqrt(2.0) << "\n\n";

    // Printing the Decimal Point
    cout << 10.0 << endl; // prints 10
    cout << showpoint << 10.0 // prints 10.0000
        << noshowpoint << endl; // revert to default format for the decimal point

    // Padding the Output
    int i = -16;
    double d = 3.14159;
    // pad the first column to use a minimum of 12 positions in the output
    cout << "i: " << setw(12) << i << "next col" << '\n'
         << "d: " << setw(12) << d << "next col" << '\n';
    // pad the first column and left-justify all columns
    cout << left
         << "i: " << setw(12) << i << "next col" << '\n' << "d: " << setw(12) << d << "next col" << '\n'
         << right; // restore normal justification
    // pad the first column and right-justify all columns
    cout << right
         << "i: " << setw(12) << i << "next col" << '\n' << "d: " << setw(12) << d << "next col" << '\n';
    // pad the first column but put the padding internal to the field
    cout << internal
         << "i: " << setw(12) << i << "next col" << '\n' << "d: " << setw(12) << d << "next col" << '\n';
    // pad the first column, using # as the pad character
    cout << setfill('#')
         << "i: " << setw(12) << i << "next col" << '\n' << "d: " << setw(12) << d << "next col" << '\n'
         << setfill(' '); // restore the normal pad character

    // Controlling Input Formatting
    // The noskipws manipulator causes the input operator to read, rather than skip, whitespace.
    /*
    char ch;
    cin >> noskipws; // set cin so that it reads whitespace
    while (cin >> ch)
        cout << ch;
    cin >> skipws; // reset cin to the default state so that it discards whitespace
    */



    // Unformatted Input/Output Operations
    // Single-Byte Operations
    char ch;
    while (cin.get(ch))
        cout.put(ch);

    // Putting Back onto an Input Stream
    // int Return Values from Input Operations
    int ch_i; // use an int, not a char to hold the return from get()
    // loop to read and write all the data in the input
    while ((ch_i = cin.get()) != EOF)
        cout.put(ch_i);
    

    // Multi-Byte Operations



    // Repositioning the Marker
    // remember the current write position in mark
    ostringstream writeStr; // output stringstream
    ostringstream::pos_type mark = writeStr.tellp();
    // ...
    // return to the remembered position
    writeStr.seekp(mark);
    
    
    return 0;
}
