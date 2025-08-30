#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iterator>

using std::cout;
using std::endl;
using std::string;
using std::vector;

// iterator
using std::back_inserter;   

// numeric
using std::accumulate;

// algorithms
using std::find;
using std::fill;
using std::fill_n;
using std::sort;
using std::unique;

/*
 * In general, the algorithms do not work directly on a container. Instead, they operate
 * by traversing a range of elements bounded by two iterators.
 * 
 * Itrators Make the Algorithms Container Independent,...
 * ...But Algorithms Do Depend on Element-Type Operations
 * 
 * 
 * Key Concept: Algorithms Never Execute Container Operations (that is different from adaptors)
 * 
 * They operate solely in terms of iterators and iterator operations. That means that algorithms
 * may change the values of the elements stored in the container, and they may move elements around
 * within the container, but they do not, however, ever add or remove elements directly.
 * 
 * 
 * The algorithms that take an input range always use their first two parameters to denote that range.
 * The most basic way to understand the algorithms is to know whether they read elements, write elements,
 * or rearrange the order of the elements.
 * 
 * 
 * Read-Only Algorithms
 * 
 * count(b, e, key)
 * find(b, e, key)
 * accumulate(b, e, initial_val) (in numeric header) 
 * 
 * 
 * Best Practices: Ordinarily it is best to use cbegin() and cend() with algotithms that
 * read, but not write, the elements. However, if you plan to use the iterator returned by
 * the algorithm to change an element's value, then you need to pass begin() and end().
 * 
 * 
 * Algorithms That Operate on Two sequences
 * 
 * equal(b1, e1, b2)    We can call equal to compare elements in containers of different types.
 *                      The element types also need not be the same as long as we can use == to 
 *                      compare the element types. It assumes that the second sequence is at least
 *                      as big as the first.
 *                      
 * 
 * Algorithms That Write Container Elements
 * 
 * fill(b, e, value)
 * fill_n(b, n, value)
 * 
 * Algorithms Do Not Check Write Operations. They assume the destination is large enough to hold
 * the number of elements being written.
 * 
 * 
 * Introducing back_inserter
 * 
 * An insert iterator is an iterator that adds elements to a container.
 * The back_inserter is defined in the iterator header. It takes a reference to a container
 * and returns an insert iterator bound to that container. When we assign through that itertor,
 * the assignment calls push_back to add an element with the given value to the container.
 * 
 * back_inserter(container &)
 * 
 * 
 * Copy Algorithms
 * 
 * copy(b1, e1, b2)     The value returned by copy is the (incremented) value of its destination iterator.
 * 
 * replace(b, e, oldVal, newVal)
 * 
 * replace_copy(b1, e1, back_inserter, oldVal, newVal)
 * 
 * 
 * Algorithms That Reorder Container Elements
 * 
 * sort(b, e)
 * unique(b, e)     reuturn the value of iterator referring the off-the-end of unique words.
 * 
 * 
 * Using Container Operations to Remove Elements
 * 
 * 
 */

void elimDups(vector<string> &words) {
    // sort words alphabetically so we can find duplicates
    sort(words.begin(), words.end());
    // unique  reorders the input range so that each word appears once in
    // the front portion of the range and returns an iterator one past the unique range
    auto end_unique = unique(words.begin(), words.end());
    // erase  uses a vecotr operation to remove the nonunique elements
    words.erase(end_unique, words.end());
}

int main(int argc, char const *argv[])
{
    std::cout << argv[0] << std::endl;
    vector<string> v{"you", "are", "genius"};

    string sum1 = accumulate(v.cbegin(), v.cend(), string(""));
    // error: no + on const char *, this call will not compile
    // string sum2 = accumulate(v.cbegin(), v.cend(), "");

    cout << sum1 << endl;

    auto inserter = back_inserter(v);
    *inserter = "!!";
    *inserter = "Oh";
    inserter = "sadII";
    // the increment and decrement operators is uneffective to back_inserter iterators.
    ++inserter;
    ++inserter;
    *inserter = "no";

    for (auto &word : v) {
        cout << word << " ";
    }
    cout << endl;
    
    return 0;
}

