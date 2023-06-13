#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::find_if;
using std::for_each;
using std::sort;
using std::stable_sort;
using std::string;
using std::vector;

/*
 * Passing a Function to an Algorithm
 *
 * Predicates
 *
 * A predicates is an expression that can be called and that returns a value
 * that can be used as a condition.
 *
 * sort(b, e, predicate)
 *
 * partition(b, e, predicate)   partition the elements by the boolean return
 * value of the predicate
 *
 *
 * Lambda Expressions
 *
 * find_if(b, e, predicate)     find the first element for which the predicate
 * returns a nonzero value
 *
 *
 * Introducing Lambdas
 *
 * We can pass any kind of callable object to an algorithm. There are two other
 * kinds of callables: classes that overloaded the function-call operator and
 * lambda expressions. The lambda expressions can be thought of as an unnamed,
 * inline function.
 *
 * [capture list] (parameter list) -> return type { function body }
 *
 * where capture list is an (often empty) list of local variables defined in the
 * enclosing function. We can omit either or both of the parameter list and
 * return type but must always include the capture list and function body: auto
 * f = [] { return 42; };
 *
 * call the lambda: cout << f() << endl;
 *
 * If we omit the return type, the lambda has an inferred return type that
 * depends on the code in the function body. If the function body is just a
 * return statement, the return type is inferred from the type of the expression
 * that is returned. Otherwise, the return type is void.  (grammer sugar)
 *
 * Note: Lambdas with function bodies that contain anything other than a single
 * return statement that do not secify a return type return void.
 *
 * A lambda may not have default arguments.
 *
 * A lambda may use a variable local to its surrounding function only if the
 * lambda captures that variable in its capture list.
 *
 *
 * The for_each Algorithm
 *
 *
 */

// the predicate
bool isShorter(const string &s1, const string &s2) {
    return s1.length() < s2.length();
}

int main(int argc, char const *argv[]) {
    vector<string> vs{"the",  "quick", "red",  "fox", "jumps",
                      "over", "the",   "slow", "red", "turtle"};
    sort(vs.begin(), vs.end(), isShorter);

    for (auto &word : vs) {
        cout << word << " ";
    }
    cout << endl;

    string::size_type sz = 4;
    sort(vs.begin(), vs.end(), isShorter);
    auto wc = find_if(vs.begin(), vs.end(),
                      [sz](const string &a) { return a.size() >= sz; });

    // for (auto last = vs.end(); wc != last; ++wc) {
    //     cout << *wc << " ";
    // }
    for_each(wc, vs.end(), [](const string &s) { cout << s << " "; });
    cout << endl;

    return 0;
}
