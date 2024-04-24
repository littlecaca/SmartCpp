#include <string>
#include <regex>
#include <iostream>

using namespace std;

/*
 * Arguments to regex_search and regex_match
 * 
 * (seq, m, r, mft)
 * (seq, r, mft)
 * 
 * regex r(re)
 * regex r(re, f)
 * r1 = re
 * r1.assign(re, f)
 * r.mark_count()   number of subexpression in r
 * r.flags()
 * 
 * Note: Constructors and assignment operations may throw exceptions of type regex_error
 * 
 * Note
 * It is important to realize that the syntactic correctness of a regular expression
 * is evaluated at run time.
 * 
 * regex_error
 * If we make a mistake in writing a regular expression, then at run time the library
 * will throw an exception (§ 5.6, p. 193) of type regex_error. 
 * 
 * 
 * Advice: Avoid Creating Unnecessary Regular Expressions
 * 
 * Compiling a regular expression can
 * regular-expression grammar or are using complicated expressions.
 * be a surprisingly slow operation, especially if you’re using the extended
 * 
 * 
 * Regular Expression Library Classes
 * 
 * Input Sequence Type      Corresponding Regular Expression Classes
 * string                       regex, smatch, ssub_match, and sregex_iterator
 * const char *                 regex, cmatch, csub_match, and cregex_iterator
 * wstring                      wregex, wsmatch, wssub_match, and wsregex_iterator
 * const wchar_t *              wregex, wcmatch, wcsub_match, and wcregex_iterator
 * 
 * The (C++) compiler will reject this code because the type of the match argument and
 * the type of the input sequence do not match. 
 * 
 * 
 * The Match and Regex Iterator Types
 * 
 * The regex iterators are iterator adaptors (§ 9.6,
 * p. 368) that are bound to an input sequence and a regex object. 
 * 
 * sregex_iterator it(b, e, r);
 * sregex_iterator end;
 * *it
 * it->
 * ++it
 * it++
 * it1 == it2
 * it1 != it2
 * 
 * 
 * match Opearations
 * 
 * m.ready()
 * m.size()
 * m.empty()
 * m.prefix()
 * m.suffix()
 * m.format(...)
 * 
 * In the operations that take an index, n defaults to zero and must less than
 * m.size(). The first submatch (the one with index 0) represents the overall match.
 * 
 * m.length(n)
 * m.position(n)
 * m.str(n)
 * m[n]
 * m.begin(), m.end()
 * m.cbegin(), m.cend()
 * 
 * Note: These operations apply to ssub_match, csub_match, wssub_match, wcsub_match
 * 
 * matched      a bool data membre indicates whether this was matched.
 * first
 * second
 * length()
 * str()
 * s = ssub     The sub_mathch object can convert to string implicitly.
 * 
 * 
 * 
 * Regular Expression Replace Operations
 * 
 * m.format(dest, fmt, mft)
 * m.format(fmt, mft)
 * 
 * regex_replace(dest, seq, r, fmt, mft)
 * regex_replace(seq, r, fmt, mft)
 * 
 * 
 * Flags to Control Matches and Formatting
 * 
 * By default, regex_replace outputs its entire input sequence. The parts that don’t
 * match the regular expression are output without change;
 */

int main(int argc, char const *argv[])
{
    // regrex
    string pattern = "[^c]ei";
    pattern = "\\w*" + pattern + "\\w*";
    regex reg(pattern, regex_constants::icase);

    smatch results;

    string test_str = "receipt Freind theif receive";
    if (regex_search(test_str, results, reg))
        cout << results.str() << endl;

    regex r2("\\w+\\.(cc|cpp|cxx)$", regex_constants::icase);
    // string raw;
    // while (cin >> raw && raw != "quit")
    //     if (regex_search(raw, results, r2))
    //         cout << results[0] << endl;

    try
    {
        regex r3("[[:alnum:]]\\w+]\\.(cc|cpp|cxx)$", regex_constants::icase);

    } catch (regex_error e)
    {
        cout << e.what() << "\n" << e.code() << endl;
    }

    cmatch results2; // will match character array input sequences
    if (regex_search("myfile.cc", results2, r2))
        cout << results2.str() << endl; // print the current match

    string file = "you are such a freind and also an ideiot";
    for (sregex_iterator it(file.begin(), file.end(), reg), end; it != end; ++it)
        cout << it->str() << endl;

    
    regex r4("([[:alnum:]]*)\\.(cc|cpp|cxx)$", regex_constants::icase);
    string raw = "jdwoaso.cpp";
    smatch res;
    if (regex_search(raw, res, r4))
    {
        cout << res.size() << endl;
        for (auto it : res)
            cout << it << endl;
    }


    // reformat numbers to ddd.ddd.ddd
    string fmt = "$2.$5.$7";


    return 0;
}
