#include <sstream>
#include <string>
#include <utility>

using namespace std;

/*
 * Function templates can be overloaded by other templates or by ordinary,
 * nontemplate functions.
 * 
 * Function matching (§ 6.4, p. 233) is affected by the presence of function templates in
 * the following ways:
 * • The candidate functions for a call include any function-template instantiation for
 * which template argument deduction (§ 16.2, p. 678) succeeds.
 * • The candidate function templates are always viable, because template argument
 * deduction will have eliminated any templates that are not viable.
 * • As usual, the viable functions (template and nontemplate) are ranked by the
 * conversions, if any, needed to make the call. Of course, the conversions used to
 * call a function template are quite limited (§ 16.2.1, p. 679).
 * • Also as usual, if exactly one function provides a better match than any of the
 * others, that function is selected. However, if there are several functions that
 * provide an equally good match, then:
 * – If there is only one nontemplate function in the set of equally good matches,
 * the nontemplate function is called.
 * – If there are no nontemplate functions in the set, but there are multiple function
 * templates, and one of these templates is more specialized than any of the
 * others, the more specialized function template is called.
 * – Otherwise, the call is ambiguous.
 * 
 * 
 * Writing Overloaded Templates
 * 
 * 
 * Missing Declarations Can Cause the Program to Misbehave
 * 
 * If the compiler can instantiate the
 * call from the template, then the missing declaration won’t matter. In this example, if
 * we forget to declare the version of debug_rep that takes a string, the compiler will
 * silently instantiate the template version that takes a const T&.
 * 
 * Tip
 * Declare every function in an overload set before you define any of the
 * functions. That way you don’t have to worry whether the compiler will
 * instantiate a call before it sees the function you intended to call.
 */

// The first version of template
template <typename T> string debug_rep(const T &t)
{
    ostringstream ret;
    ret << t;
    return ret.str();
}

// The second version of template
template <typename T> string debug_rep(const T *p)
{
    ostringstream ret;
    ret << "pointer: " << p;            // print the pointer's own value
    if (p)
        ret << " " << debug_rep(*p);    // print the value to which p points
    else
        ret << " null pointer";         // or indicate that the p is null
    return ret.str();                   // return a copy of the string to which ret is bound
}

// print strings inside double quotes
string debug_rep(const string &s)
{
    return '"' + s + '"';
}

// convert the character pointers to string and call the string version of debug_rep
string debug_rep(char *p)
{
    return debug_rep(string(p));
}

string debug_rep(const char *p)
{
    return debug_rep(string(p));
}

int main(int argc, char const *argv[])
{
    string s = "";
    debug_rep(s);   // first version, only 1 viable
    debug_rep(&s);  // second version, both two are viable
    
    const string *s2 = &s;
    debug_rep(s2);  // the second version is more specialized

    debug_rep("sd");

    int i = 21;
    const int *si = &i;
    debug_rep(si);
    return 0;
}
