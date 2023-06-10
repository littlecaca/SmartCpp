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
 * Constraints on Types That a Container Can Hold
 *
 * We can define a container for a type that does not support an operation-specific requirement, but we
 * can use an operation only if the element type meets that operations's requirements.
 * As an example, the sequential container constructor that takes a size argument uses the element
 * type's default constructor. Some classes do not have a default constructor. We can define a 
 * container that holds objects of such types, but we cannot construct such containers using only an 
 * element count.
 * 
 * 
 * Common Container Operations and members, types and so forth.
 * 
 * Type Alias
 * 
 * iterator
 * const_iterator
 * size_type
 * difference_type
 * value_type
 * reference
 * const_reference
 * 
 * Construction
 * 
 * C c;
 * C c1(c2);    c1 and c2 must have the same type, for array, they must also have the same size
 * C c(b, e);   not valid for array
 * C c{a, b, c};
 * 
 * Assignment ad swap
 * 
 * c1 = c2          c1 and c2 must have the same type, for array, they must also have the same size
 * c1 = {a, b, c}   not valid for array
 * c1.swap(c2)      swap is usually much faster than copying elements from c2 to c1
 * swap(c1, c2)
 * 
 * The assign operations not valid for associative containers or array
 * 
 * seq.assign(b, e)
 * seq.assign(il)       il is a initializer list
 * seq.assign(n, t)     
 * 
 * Size
 * 
 * c.size()
 * c.max_size()
 * c.empty()
 * 
 * Add/Remove Elements (not valid for array)
 * 
 * c.insert(args)
 * c.emplace(inits)
 * c.erase(args)
 * c.clear()
 * 
 * Equality and Relational Operations
 * 
 * ==, !=
 * <, <=, >, >= (not valid for unordered associative containers)
 * 
 * Obtain Iterations
 * 
 * c.begin(), c.end()
 * c.cbegin(), c.cend()
 * 
 * Additional Members of Reversible Containers (not valid for forward_list)
 * 
 * reverse_iterator
 * const_reverse_iterator
 * c.rbegin(), c.rend()
 * c.crbegin(), c.crend()
 * 
 * Constructors that take a size are valid for sequential containers (not including array) only
 * 
 * C seq(n)     not valid for string
 * C seq(n, t)
 * 
 * 
 * Itertors
 * 
 * With one exception, the container iterators support all the basic operations. The 
 * exception is that forward_list iterators do not support the decrement(--) operator.
 * The iterator arithmetic operations apply only to iterators for string, vector, deque and array.
 * 
 * 
 * Iterator Ranges
 * 
 * [begin, last)
 * 
 * 
 * When write access is not needed, use cbegin and cend.
 * 
 * 
 * Defining and Initializing a Container
 * 
 * Every container type defines a default constructor with the exception of array. Again excepting
 * array, the other constructors take arguments that specify the size of the container and initial
 * values for the elements.
 * 
 * 
 * Initializing a Container as a Copy of Another Container
 * 
 * When we pass iterators, there is no requirement that the container type be identical. Moreover,
 * the element types in the new and original containers can differ as long as it is possible to convert
 * the elements. When we initialize a container as a copy of another container, the container type
 * and element type of both containers must be identical.
 * 
 * 
 * List Initialization 
 * 
 * 
 * Sequential Container Size-Related Constructors (only supported for sequential containers
 * , not including associative containers)
 * 
 * C seq(n, t)
 * C seq(n)
 * 
 * If the element type does not have a default constructor, then we must specify an explicit
 * element intializer along with the size.
 * 
 * 
 * Library arrays Have Fixed Size
 * 
 * Even though we cannot copy or assign objects of built-in array types, there is no 
 * such restriction on array.
 * 
 * As with any container, the initializer must have the same type as the container we
 * are creating. For arrays, the element type and the size must be the same, because
 * the size of an array is part of its type.
 * 
 * 
 * Assignment and Swap
 * 
 * The array does not support assign(member function).
 * 
 * Assignment related operations invalidate iterators, references, and pointers into the
 * left-hand container. Aside from string they remain valid after swap, and (excepting arrays)
 * the containers to which they refer are swapped.
 * 
 * With the exception of arrays, swapping two containers is guaranteed to be fast--the elements
 * themselves are not swapped; internal data structures are swapped. Excepting array, swap does not
 * copy, delete, or insert any elements and is guaranteed to run in constant time.
 * 
 * The nonmember swap version is of most importance in generic programs. As a matter of
 * habit, it is best to use the nonmember version of swap.
 * 
 * 
 * Container Size Operations
 * 
 * size()  not supported for forward_list
 * empty()
 * max_size()
 * 
 * 
 * Relational Operators
 * 
 * The right- and left-hand operands must be the same kind of container and must hold elements of the
 * same type. 
 * 
 * Relational operators use their element's relational operator.We can use relational operator
 * to compare two containers only if the appropriate comparsion coperator is defined for the element type.
 * The container equality operators use the element's == operator, and the relational operators use
 * the element's < operator.
 */

int main(int argc, char const *argv[])
{
    /* code */
    deque<double> d1(10);
    
    array<double, 3> a1;    // wow!!


    list<double> l1{21.34, 32.343, 3243.23, 324.34};
    vector<int> v1(l1.begin(), l1.end());

    for (auto elem : v1) {
        cout << elem << " ";
    }
    cout << endl;


    // the array container can be copy or assigned
    array<int, 10> nums;    // defaulted-initialized

    for (auto i : nums) cout << i << " ";
    cout << endl;

    nums = {1, 2, 3, 4};    // the remaining elements will be value initailized
    
    for (auto i : nums) cout << i << " ";
    cout << endl;

    array<int, 10> nums2 = nums;
    
    // indeed, the array supports assign
    nums2 = {0};
    cout << "size of nums2: " << sizeof nums2 << endl;
    cout << nums.max_size() << endl;
    return 0;
}
