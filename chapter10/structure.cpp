#include <iostream>
#include <algorithm>
#include <list>
#include <forward_list>
#include <vector>

using namespace std;

/*
 * The most fundamental property of any algorithm is the list of operations it
 * requires from its iterators.
 * 
 * The sort algorithm needs to randomly access elements.
 * 
 * 
 * Iterator Categories
 * 
 * Input iterator       Read, but not write; single-pass, increment only
 * 
 * ==, !=
 * ++       We are guaranteed that *it++ is valid, but incrementing an input iterator may
 *          invalidate all other iterators into the stream.
 * 
 * *
 * ->
 * 
 * Output iterator      Write, but not read; single-pass, increment only
 * 
 * ++
 * *            May appear only as the left-hand side of an assignment
 * 
 * Forward iterator     Read and write; multi-pass, increment only
 * 
 * Bidirectional iterator   Read and write; multi-pass, increment and decrement
 * 
 * 
 * Random-access iterator   Read and write; multi-pass, full iterator arithmetic
 * 
 * <, <=, >, >=
 * +, +=, -, -=
 * -,
 * []
 * 
 * find -> input iterator
 * replace -> forward iterator
 * reverse -> bidirectional iterator
 * unique -> forward iterator
 * 
 * 
 * Algorithm Parameter Patterns
 * 
 * Most algorithms have one of the following four forms:
 * 
 * alg(beg, end, other args);
 * alg(beg, end, dest, other args);
 * alg(beg, end, beg2, other args);         These algorithms typically use the elements from the 
 * alg(beg, end, beg2, end2, other args);   second range in combination with the input range to 
 *                                          perform a computation.
 * 
 * 
 * Algorithm Naming Conventions
 * 
 * Some Algorithms Use Overloading to Pass a Predicate
 * 
 * unique(beg, end);
 * unique(beg, end, comp);
 * 
 * Algorithms with _if Versions
 * 
 * Algorithms that take an element value typically have a second named (not overloaded)
 * version that takes a predicate in place of the value.
 * 
 * find(beg, end, val)
 * find_if(beg, end, pred)
 * count(beg, end, val)
 * count_if(beg, end, pred)
 *  
 * Distinguishing Versions That Copy from Those That Do Not
 * 
 * reverse(beg, end)
 * reverse_copy(beh, end, dest)
 * remove_if(b, e, pred)
 * remove_copy_if(b, e, dest, pred)
 * 
 * 
 * replace(b, e, old_val, new_val);
 * replace_if(b, e, pred, new_val);
 * replace_copy(b, e, dest, old_val, new_val);
 * replace_copy_if(n, e, dest, pred, new_val);
 */

int main(int argc, char const *argv[])
{
    /* code */
    list<int> li;
    forward_list<int> fi;
    reverse(li.begin(), li.end());
    unique(fi.begin(), fi.end());
    return 0;
}
