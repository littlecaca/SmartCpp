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
    string s5(s, 4, 3);

    
    return 0;
}
