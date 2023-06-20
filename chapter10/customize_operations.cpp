#include <algorithm>
#include <functional>
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
using std::transform;
using std::bind;
using std::ref;
using namespace std::placeholders;

/*
 * Passing a Function to an Algorithm
 *
 * Predicates
 *
 * A predicates is an expression that can be called and that returns a value
 * that can be used as a condition.
 *
 * sort(b, e, predicate)        can't be used to list
 * stable_sort(b, e, predicate)
 *
 * partition(b, e, predicate)   partition the elements by the boolean return
 *                              value of the predicate
 * stable_partition(b, e, predicate)
 * 
 * 
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
 * lambda captures that variable in its capture list. And the capture list is used for 
 * local nonstatic variables only.
 *
 *
 * The for_each Algorithm
 *
 * for_each(b, e, predicate)
 * 
 * 
 * Lambda Captures and Return
 * 
 * When we define a lambda, the compiler generates a new (unamed) class
 * type (compiler-generated class type) that corresponds to that lambda. The type contains the data member corresponding
 * to the variables captured by the lambda. The data members of a lambda are initialized
 * when a lambda object is created.
 * 
 * 
 * Capture by Value
 * 
 * Unlike parameters, the value of a captured variable is copied when the lambda (object)
 * is created, not when it is called.
 * 
 * Lambda Capture List
 * 
 * []
 * 
 * [names]
 *  
 * [&]      Implicit by reference capture list.
 * 
 * [=]      Implicit by value capture list.
 * 
 * [&, identifier_list]
 * 
 * [=, reference_list]
 * 
 * We can also return a lambda from a function. If the functon returns a lambda,
 * that lambda must not contain regerence captures.
 * 
 * Advice: Keep Your Lambda Captures Simple, 
 * If Possible Avoid Capturing Pointers or References
 * 
 * Code that executes between when the lambda is created and when it executes
 * might change the value of the object to which the lambda capture points (or refers).
 * 
 *
 * Implicit Captures
 * 
 * We can also mix implicit and explicit captures.
 * 
 * 
 * Mutable Lambdas
 * 
 * By default, a lambda may not change the value of a variable that it copies by value.
 * mutable must follow the parameter list, so we can not omit the parameter list
 * auto f = [v1] () mutable { return ++v1; };
 * 
 * 
 * Specifying the Lambda Return Type
 * 
 * transform(b1, e1, b2, predicate)
 * 
 * 
 * Binding Arguments
 * 
 * The library function named bing is defined in the `functional` header. The bind
 * function can be thought of as a general-purpose function adaptor. It takes a callable
 * object and generates a new callable that "adapts" the parameter list of the original object.
 * 
 * auto newCallable = bind(callable, arg_list);
 * where newCallable is itself a callable object.
 * 
 * bool check_size(const string &s1, string::size_type sz);
 * auto check6 = bind(check_size, _1, 6);  
 * we get bool check6(const string &s1);
 * 
 * Using placeholders Names
 * 
 * The namespace placeholders is itself defined inside the std namespace.
 * And the placeholders namespace is defined in the functional header like bind function. 
 * using std::placeholders::_1
 * 
 * We can use a different form of using:
 * using namespace namespace_name;
 * 
 * 
 * Arguments to bind
 * 
 * More generally, we can use `bind` to bind or rearrange the parameters in the given callable.
 * like:    auto g = bind(f, a, b, _2, c, _1)
 * 
 * Using to `bind` to Reorder Parameters
 * 
 * sort(words.begin(), words.end(), bind(isShorter, _2, _1));
 * 
 * 
 * Binding Reference Parameters
 * 
 * bind function will copy its arguments, and sometimes we want to pass references.
 * In this case, we must use the library ref function.
 * The ref function returns an object that contains the given reference and that is itself copyable.
 * There is also a cref function that generates a class that holds a reference to const.
 * Like bind, the ref and cref functions are defined in the functional header.
 * 
 * 
 * Backward Compatibility: Binding Arguments
 * 
 * bind1st
 * bind2nd
 * This two are too limited and have been deprecated.
 */

std::ostream &print(std::ostream &os, const string &s, char c) {
    return os << s << c;
}

// the predicate
inline bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

int main(int argc, char const *argv[]) {
    vector<string> vs{"the",  "quick", "red",  "fox", "jumps",
                      "over", "the",   "slow", "red", "turtle"};
    sort(vs.begin(), vs.end(), isShorter);

    // copy a `reference to vs` to the callable object named f
    auto f = [&vs]() { return true; };
    
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


    // binding reference parameters
    for_each(wc, vs.end(), bind(print, ref(cout), _1, '|'));
    cout << endl;
    return 0;
}
