#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

/*
 * Other Ways to Construct strings
 *
 * The string type supports three more constructors.
 * 
 * string s(cp, n);     s is a copy of the first n characters in the array to which cp points.
 * string s(s2, pos2);  s is a copy of the characters in the string s2 starting at the index pos2.
 *                      If pos2 > s2.size(), throws an out_of_range exception
 * string s(s2, pos2, len2);    s is a copy of len2 characters from s2 starting at the index pos2.
 *                              Throw an out_of_range exception if pos2 > s2.size(). Regradless of 
 *                              the value of len2, copies at most s2.size() - pos2 characters.
 * 
 * 
 * The substr Operation
 * 
 * s.substr(pos)
 * s.substr(pos, n)
 * 
 * 
 * Other Ways to Change a string
 * 
 * s.insert(pos, n, c);     Versions taking an index rather than iterator return a reference to s.
 * s.erase(pos, n);         Remove n characters starting at position pos. If n is omitted, removes until the end.
 *                          Return a reference to s.
 * s.assign(cp, n); 
 * 
 *         Return a reference to s.
 * s.insert(pos, cp);
 * 
 * We can also specify the characters to insert or assign as coming from another string or substring thereof.
 * 
 * s.insert(pos, s2);
 * s.insert(pos, s2, 0, s2.size());
 * 
 * The append and replace Functions
 * 
 * s.append(s2/cp) == s.insert(s.size(), s2/cp);    Return a reference to s.
 * 
 * 
 * Operations to Modify strings
 * 
 * s.insert(pos, args)
 * s.erase(pos, len)
 * s.assign(args)
 * s.append(args)
 * s.replace(range, args)  
 * 
 * args can be one of the following; append and assign can use all forms.
 * 
 *                 replace            replace       insert          insert
 *              (pos, len, args)    (b, e, args)    (pos, args)    (iter, args)
 * str                y                 y               y               n
 * str, pos, len      y                 n               y               n
 * cp, len            y                 y               y               n
 * cp                 y                 y               n(but y)        n
 * n, c               y                 y               y               y
 * b2, e2             n                 y               n               y
 * initializer list   n                 y               n               y
 * 
 * 
 * The replace operations are a shorthand way of calling erase and insert.
 * We can insert a larger or smaller string:
 * 
 * s.replace(11, 3, "Fifth");   // s == "C++ Primer Fifth Ed"
 * 
 * In this call we remove three characters but insert five in their place.
 * 
 * When you use the form of "b, e" into range, you cannot exceed the range, or 
 * it will throw a std::out_of_range exception.
 * 
 * 
 * string Search Operations
 * 
 * The string class provides six different search functions, each of which has 
 * four overloaded versions. If there is no match, the function returns a static
 * member named string::npos (a const string::size_type initialized with the value -1).
 * Because npos is an unsigned type, this initializer means npos is equal to the largest
 * possible size any string could have.
 * 
 * s.find(args)
 * s.rfind(args)
 * s.find_first_of(args)        Find the first occurrence of any character from args in s
 * s.find_last_of(args)         
 * s.find_first_not_of(args)    Find the first character in s that is not in args
 * s.find_last_not_of(args)
 * 
 * args must be one of:
 * c, pos           pos defaults to 0
 * s2, pos          pos defaults to 0
 * cp, pos          pos defaults to 0
 * cp, pos, n       Look for the first n characters in the array pointed to by the pointer cp.
 *                  Start looking at position pos in s. No default for pos or n.
 * 
 * Warning: The string search functions return string::size_type which is an unsigned type.
 * 
 * 
 * The compare Functions
 * 
 * Possible Arguments to s.compare
 * 
 * s2
 * pos1, n1, s2
 * pos1, n1, s2, pos2, n2
 * 
 * cp
 * pos1, n1, cp
 * pos1, n1, cp, n2
 * 
 * 
 * Numeric Conversions
 * 
 * to_string(val)   val can be any arithmetic type.
 * stoi(s, p, b)    b indicates the numeric base to use for the conversion; b defaults to 10.
 *                  p is a pointer to a size_t in which to put the index of the first nonnumeric
 *                  character in s; p defaults to 0, in which case the function does not store the index.
 * stol(s, p, b)
 * stoul(s, p, b)
 * stoll(s, p, b)
 * stoull(s, p, b)
 * 
 * stof(s, p)
 * stod(s, p)
 * stold(s, p)
 * 
 * Note: If the string can't be converted to a number, these functions throw an invalid_argument
 * exception. If the conversion generates a value that can't be represented, they throw out_of_range.
 */

int main(int argc, char const *argv[])
{   
    // constructors that string shares with the other sequential containers.
    string s{'1', '2'};
    cout << s << endl;
    string s2(s.begin(), s.end());

    // string s(cp, n)
    string s3("you are my hero", 7);
    cout << s3 << endl;

    // string s(s2, pos2)
    string s4(s, 1);

    // string s(s2, pos2, len2)
    string s5(s, 1, 3);

    s.insert(1, "you");
    
    cout << s << endl;

    string::size_type p = 0;

    string numstr("ab");
    string numstr2("0x12");
    cout << std::stoi(numstr, &p, 16) << endl;
    cout << p << endl;
    cout << std::stoi(numstr2, &p) << endl;
    cout << p << endl;

    auto sp = s3.c_str();
    s3.append("aha");
    cout << sp << endl;
    
    return 0;
}
