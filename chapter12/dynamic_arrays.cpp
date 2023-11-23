#include <iostream>
#include <vector>
#include <memory>
#include <string>

using std::cout;
using std::endl;
using std::shared_ptr;
using std::string;
using std::unique_ptr;
using std::allocator;
using std::vector;
// Defined in the memory header
using std::uninitialized_copy;
using std::uninitialized_copy_n;
using std::uninitialized_fill;
using std::uninitialized_fill_n;


/*
 * Best Practices
 *
 * Most applications should use a library container rather than dynamically
 * allocated arrays. Using a container is easier, less likely to contain
 * memory-management bugs, and is likely to give better performance.
 *
 *
 *
 * Warning
 *
 * It is important to remember that what we call a dynamic array does not
 * have an array type.
 *
 * If there are more initializers than the given size, then the `new` expression
 * fails and no storage is allocated. In this case, `new` throws an exception of
 * type bad_array_new_length, which is defined in the new header like bad_alloc.
 *
 *
 *
 * It Is Legal to Dynamically Allocate an Empty Array
 *
 * int *p = new int[n]  // This code works fine if n equals 0.
 *
 * When we use new to allocate an array of size zero, `new` returns
 * a valid, nonzero pointer.
 *
 *
 *
 * Freeing Dynamic Arrays
 *
 * delete[] pa;
 * Elements in an array are destroyed in reverese order.
 * Recall that when we use a type alias that defines an array
 * type, we can allocate an array without using []. Even so,
 * we must use brackets when we delete a pointer to that array.
 *
 *
 *
 * Smart Pointers and Dynamic Arrays
 *
 * unique_ptrs to Arrays
 *
 * unique_ptr<T[]> u            u can point to a dynamically allocated array of type T. 
 * unique_ptr<T[]> u(p)         u points to the dynamically allocated array to
 *                              which the built-in pointer p points. p must be convertible to T*.
 *
 * u[i]                     Returns the object at position i in the array that u
 *                          owns. u must point to an array.
 *
 * If we want to use a shared_ptr to manage a dynamic array, we must provide
 * our own deleter. shared_ptrs don't have subscript operator and don't support pointer
 * arithmetic.
 * 
 * 
 * 
 * The allocator Class
 * 
 * Classes that do not have default constructors cannot be 
 * dynamically allocated as an array. The allocator class provides
 * type-aware allocation of raw, unconstructed memory.
 * 
 * Operations that allocator supports
 * 
 * allocator<T> 
 * a.allocate(n)        Allocate row, unconstructed memory to hold n objects of type T.
 * a.deallocate(p, n)   p must be a pointer previously returned by allocate,
 *                      and n must be the size requested when p was created.
 *                      The uset must run destroy on any obejcts before calling deallocate.
 * a.construct(p, args)
 * a.destroy(p)         Runs the destructor on the object pointed to by the T* pointer p.
 *
 * 
 * Warning: 
 * We must construct objects in order to use memory returned by allocate.
 * Using unconsturcted memory in other ways is undefined.
 * 
 * We may destroy only elements that actually constructed.
 * 
 * The pointer we pass to deallocate cannot be null; 
 * 
 * 
 * 
 * Algorithms to Copy and Fill Uninitialized Memory
 * 
 * uninitialized_copy(b, e, b2)
 * 
 * uninitialized_copy_n(b, n, b2)
 * 
 * uninitialized_fill(b, e, t)
 * 
 * uninitialized_fill_n(b, n, t)
 * 
 * 
 */

int main(int argc, char const *argv[]) {
    // new allocates the requested number of objects
    int size = 89;
    int *pia = new int[size]();
    int *pia2 = new int[12]{1, 2, 3, 4};
    string *psa = new string[10]{"a", "bs", string(3, 'e')};

    // We must use brackets when we delete a pointer to that array
    typedef int arrT[42];
    int *p = new arrT;
    delete[] p;

    // up points to an array of ten uninitialized ints
    unique_ptr<int[]> up(new int[10]);

    // We can use the subscript operator to access the elements in the array.
    for (size_t i = 0; i != 10; ++i) {
        up[i] = i;
    }
    up.reset();

    // Using a shared_ptr to manage a dynamic array
    shared_ptr<int> sp(new int[10], [](int *p) { delete[] p; });

    // Access element by a shared_ptr pointing to a dynamically allocated array
    for (size_t i = 0; i != 10; ++i) {
        *(sp.get() + i) = i;    // use get to get a built-in pointer
    }
    sp.reset();
    
    // Allocate 12 unconstructed string objects
    allocator<string> alloc;
    auto const sp2 = alloc.allocate(12);
    auto q = sp2;

    alloc.construct(q++, 10, 'c');
    alloc.construct(q++, "you");
    alloc.destroy(--p);
    alloc.destroy(--p);

    // Free the memory
    alloc.deallocate(sp2, 12);
    

    // Allocate twice as many elements as vi holds
    vector<int> vi{1, 2, 3, 4, 5};
    allocator<int> alloc_int;
    auto pi3 = alloc_int.allocate(vi.size() * 2);
    // Construct elements starting at p as copies of elemrnts in vi
    auto q2 = uninitialized_copy(vi.begin(), vi.end(), pi3);
    // Initialize the remaining elements to 42
    uninitialized_fill_n(q2, vi.size(), 42);

    
    return 0;
}
