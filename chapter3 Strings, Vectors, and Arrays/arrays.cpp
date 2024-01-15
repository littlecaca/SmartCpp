#include <iostream>
#include <iterator>
#include <cctype>
#include <cstddef>

/*
 * Arrays are a compound type.
 *
 * The dimension must be constexpr, and if dimension is greater than
 * the number of initializers, the initializers are used for the first
 * elements and any remaining elements are value initialized. Please pay
 * attention that the value initialization is different from the default
 * initialization.
 *
 *
 * No Copy or Assignment For Arrays.
 *
 *
 * When we use a variable to subscript an array, we normally should define
 * that variable to have type size_t, which in defined in the cstddef header
 * and is guaranteed to be large enough to hold the size of any object in memory.
 *
 *
 * Checking Subscript Values
 *
 * The most common source of security problems are buffer overflow bugs.
 * Such bugs occur when a program fails to check a subscript and mistakenly
 * uses memory outside the range of an array or similar data structure.
 *
 *
 * Pointers Are Iterators
 *
 * In particular, pointers to array elements support the same operations as iterators
 * on vectors or strings.
 *
 *
 * The Library begin and end Functions
 *
 * These functions act like the similarly named container members. But they are not
 * members of class. Instead, they take an argument that is an array. These functions
 * are defined in the iterator header.
 *
 * The result of subtracting two pointers is a library type named ptrdiff_t, like size_t,
 * which is defined in the cstddef header.
 */

int main(int argc, char const *argv[])
{
	// char a[6] = "Daniel";	// error: the compiler does not allow it
	// But this can be compiled in C. Oh, interesting!
	char a[7] = "Daniel";

	int b[7];
	// the sizeof operator retures the number of byte
	std::cout << "size:" << sizeof(b) << std::endl;

	std::cout << a[0] << std::endl;

    /*
     * Pointers and Arrays
     *
     * Arrays have a special property--in most places when we use an array,
     * the compiler automatically substitues a pointer to the first element.
     */
    int a1[3][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    auto a2 = a1;   // the a2 is a pointer to int
    /*
     * The compiler treats the above initialization as if we had writen:
     *      auto a2 = &(a1[0])
     */

    decltype(a1) a3 = { // a3 is an 3x3 array
        1, 1, 4, 0, 8
    };

    int a4[3] = {1, 2, 4};
    int *pas = a4;
    int *pae = &a4[3];    // pointer just past the last element in a1
    // these equals
    int *beg = std::begin(a4);
    int *last = std::end(a4);
    std::ptrdiff_t n = beg - last;

    if (!std::isalnum(*a4))
        std::cout << "no" << std::endl;
    std::cout << *beg << " " << *pas << std::endl;
	std::cout << n << " elements" << std::endl;

    // this can be compiled, but it is not valid.
    // because i and sz are unrelated objects.
    int i = 0, sz = 42;
    int *pi = &i, *ps = &sz;
    if (pi > ps)
        std::cout << "yes" << std::endl;
    else
        std::cout << "no" << std::endl;

    // unlike subscripts for vector and string, the index of the built-in
    // subscript operator is not an unsigned type
    int k = a4[-2]; // a4[-2] is the same element as a4[0]
    return 0;
}