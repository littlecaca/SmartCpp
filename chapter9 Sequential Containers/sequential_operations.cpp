#include <iostream>
#include <deque>
#include <array>
#include <forward_list>
#include <list>
#include <vector>

using std::deque;
using std::forward_list;
using std::vector;
using std::list;
using std::string;
using std::array;
using std::cout;
using std::cin;
using std::endl;

/*
 * Adding Elements to a Sequential Container (not valid for array)
 *
 * c.push_back(t)       not valid for forward_list, return void
 * c.emplace_back(args) constructed from args at the end of c, not valid for forward_list, return void
 * 
 * c.push_front(t)      not valid for vector and string, return void
 * c.emplace_front(args)   not valid for vector and string, return void
 * 
 * c.insert(p, t)       return an iterator referring the element we just added
 * c.emplace(p, args)
 * 
 * c.insert(p, n, t)    insert n elements brefore the element denoted by iterator p, return an iterator
 *                      referring the first element inserted. if n is zero, return p
 * c.insert(p, b, e)
 * 
 * c.insert(p, il)      il is a braced list of element values. Insert the given values before the element
 *                      denoted by the iterator p
 * 
 * Adding elements to a vector, string, or deque potentially invalidates all existing iterators, references,
 * and pointers into the container.
 * 
 * It is legal to insert anywhere in a vector, deque, or string. However, doing so can be an expensice operation.
 * 
 * The emplace functions construct elements in the container. The arguments to these functions must match a
 * constructor for the element type (may be default constructor)
 * 
 * 
 * Key Concept: Container Elements Are Copies
 * 
 * 
 * Accessing Elements
 * 
 * at and subscript operator valid only for string, vector, deque, and array. back not valid for forward_list.
 * The result is undefined if the container has no the element needed.
 * 
 * c.back()
 * c.front()
 * c[n]
 * c.at(n)  if the index is out of range, throws an out_of_range exception
 * 
 * Calling front or back on an empty container, like using a subscript that is out of range,
 * is a serious programming error.
 * 
 * 
 * The Access Members Return References
 * 
 * c.front() = 42;
 * auto &v = c.back();
 * v = 42;
 * 
 * As usual, if we use `auto` to store the return from one of these functions and we want to use that
 * variable to change the element, we must remember to define our variable as a reference type.
 * 
 * 
 * Erasing Elements
 * 
 * These operations are not supported by array. pop_back not valid for forward_list; pop_front not valid
 * for vector and string.
 * 
 * c.pop_back()     undefined if c is empty. return void.
 * c.pop_front()    
 * c.erase(p)       return an iterator to the element after the one deleted or the off-the-end iterator if
 *                  p denotes the last element. undefined if p is the off-the-end iterator.
 * c.erase(b, e)
 * c.clear()        return void
 * 
 * Removing elements anywhere but the beginning or end of a deque invalidates all iterators, references, pointers.
 * Iterators, references, and pointers to elements after the erasure point in a vector or string are invalidated.
 * 
 * Warning: The members that remove elements do not check their argument(s). The programmer must ensure that element(s)
 * exist before removing them.
 * 
 * 
 * Specialized forward_list Operations
 * 
 * Operations to Insert or Remove Elements in a forward_list
 * 
 * lst.before_begin()       Iterator denoting the nonexistent element.
 * lst.cbefore_begin()      returns a const_iterator
 * lst.insert_after(p, t)
 * lst.insert_after(p, n, t)
 * lst.insert_after(p, b, e)
 * lst.insert_after(p, il)
 * 
 * lst.emplace_after(p, args)
 * 
 * lst.erase_after(p)
 * lst.erase_after(b, e)  deletes from the one after b. Returns an iterator to the element after the one deleted, or
 *                        the off-the-end iterator if there is no such element.
 * 
 * 
 * Resizing a Container (not supported by arrays)
 * 
 * If the current size is greater than the requested size, elements are deleted from the back of the container;
 * if the current size is less than the new size, elements are added to the back of the container.
 * 
 * c.resize(n)      if n < c.size(), the excess elements are discarded. If n > c.size(), the added elements are value initialized.
 * c.resize(n, t)
 * 
 * Resize on a vector, string, or deque potentially invalidates all iterators, pointers, and references.
 * 
 * 
 * Container Operations May Invalidate Iterators
 * 
 * Advice: Managing Iterators
 * 
 * When you use an iterator (or reference or pointer to a container element), it is a good idea to
 * minimize the part of the program during which an iterator must stay valid. You need to ensure that
 * the iterator is repositioned, as appropriate, after each operation that changes the container. This 
 * advice is especially important for vector, string, and deque.
 * 
 * Avoid Storing the Iterator Returned from end
 * 
 * When we add or remove elements in a vector or string, or add elements or remove any but the first element in a deque, the
 * iterator returned by end is always invalidated. Thus, loops that add or remove elements should always call end rather than
 * use a stored copy. Partly for this reason, C++ standard libraries are usually implemented so that calling end() is a very 
 * fast operation.
 * 
 * 
 */

int main(int argc, char const *argv[])
{
    /* code */
    deque<int> d1{1, 2, 3, 4};
    deque<int> &rd1 = d1;
    d1.insert(d1.end(), {7, 1, 2, 3, 4, 5, 64, 4,4,4,4,4,4,4,4,4,4,4,4,4,44,4,4,4,4,4,4,});

    for (auto i : rd1) {
        cout << i << " ";
    }
    cout << endl;

    forward_list<int> fi{1, 2, 3};
    auto it = fi.begin();
    

    for (auto e : fi) {
        cout << e << " ";
    }
    cout << endl;
    
    return 0;
}
