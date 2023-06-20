#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

/*
 * Insert iterators
 *
 * An inserter is an iterator adaptor that takes a container and yields an iterator that adds
 * elements to the specified container. 
 * 
 * Insert Iterator Operations
 * 
 * it = t   Depending on the kind of insert iterator, calls c.push_back(t), c.push_front(t) or c.insert(t, p)
 * 
 * *it, ++it, it++  exist but do nothing to it, returns it
 * 
 * Three kinds of them: back_inserter, front_inserter, inserter
 * The inserter takes a second argument, which must be an iterator into the given container.
 * 
 * 
 * Stream iterators
 * 
 * istream_iterator
 * 
 * istream_iterator<T> in(is)
 * istream_iterator<T> end;     Off-the-end iterator for an istream_iterator that reads values of type T.
 * 
 * in1 == in2   in1 and in2 must read the same type. 
 * in1 != in2   They are equal if they are both the end value or are bound to the same input stream.
 * *in
 * in->mem
 * ++in, in++   Reads the next value from the input stream using the >> operator for the element type.
 *              As usual, the prefix version returns a reference to the incremented iterator.
 *              The postfix version returns the old value.
 * 
 * ostream_iterator
 * 
 * ostream_iterator<T> out(os);
 * ostream_iterator<T> out(os, d);  out writes values of type T followed by d to output stream os.
 *                                  d points to a null-terminated character array.
 * out = val
 *  
 * *out, ++out, out++   Exist but do nothing. Each operator returns out.
 * 
 * Using Stream Iterators with the Algorithms
 * such as accumulate.
 * 
 * istream_iterators Are Permitted to Use Lazy Evaluation
 * 
 * The implementation is permitted to delay reading the stream util we use the iterator.
 * 
 * An ostream_iterator can defined for any type that has an output operator.
 * Each time we assign a value to out_iter, the write is committed.
 * 
 * Using Stream Iterators with Class Types
 * 
 * 
 * Reverse iterators
 * 
 * reverse_iterator.base()  get the ordinary iterator corresponding to the reverse iterator
 * 
 * 
 * Move iterators
 */


int main(int argc, char const *argv[])
{
    string s = "2";
    s.append("2").append("3");
    cout << s << endl;

    vector<string> vs{"That", "is", "unacceptable"};
    ostream_iterator<string> os_iter(cout, " ");
    
    copy(vs.begin(), vs.end(), os_iter);
    cout << endl;

    return 0;
}
