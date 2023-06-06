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
 * Overview
 *
 * Containers offer different performance trade-offs relative to
 *      1. The costs to add or delete elements to the container
 *      2. The costs to perform nonsequential access to elements of the container
 * 
 * vector   flexible-size array. Supports random access. 
 *          Inserting or deleting other than at the back may be slow.
 * 
 * deque    double-end queue. Supports random access.
 *          Fast insert/delete at front or back.
 * 
 * list     doubly linked list. Supports only bidirectional sequential access.
 *          Fast insert/delete at any point in the list.
 * 
 * forward-list     Signly linked list. Supports only sequential access in one direction.
 *                  Fast insert/delete at any point in the list.
 * 
 * array    fixed-size array. Supports fast random access.
 *          Cannot add or remove elements.
 * 
 * string   A specialized container, similar to vector, that contains characters.
 *          Fast random access. Fast insert/delete at the back.
 * 
 * string and vector hold their elements in contiguous memmory. 
 * 
 * An array is a safer, easier-to-use alternative to built-in arrays.
 * 
 * A forward_list is intended to be comparable to the best handwritten, singly linked list.
 * Consequently, forward_list does not have the size operation because storing or computing
 * its size would entail overhead compared to a handwritten list. For the other containers, size
 * is guaranteed to be a fast, constant-time operation.
 * 
 * Modern C++ programs should use the library containers rather than more primitive structures
 * like arrays.
 * 
 * 
 * Deciding Which Sequential Container to Use
 * 
 *      1. it is best to use vector unless there is a good reason to prefer another container.
 *      2. if your has lots of small elements and space overhead matters, don't use list or forward_list
 *      3. if the program requires random access to elements, use a vector or a deque
 *      4. if the program needs to insert or delete elements in the middle of the container, 
 *         use a list or forward_list
 *      5. If the program needs to insert or delete elements at the front and the back, but not in the
 *         middle, use a deque.
 * 
 * If you're not sure which container to use, write your code so that it uses only operations
 * common to both vectors and lists: Use iterators, not subscripts, and avoid random access to elements.
 * That way it will be easy to use either a vector or a list as necessary.
 */

int main(int argc, char const *argv[])
{
    /* code */
    deque<int> d1;
    d1.push_back(1);
    d1.push_front(2);
    
    for (auto &elem : d1) {
        cout << elem << endl;
    }
    cout << d1.size() << endl;

    return 0;
}
