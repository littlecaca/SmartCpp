#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::endl;


int main(int argc, char const *argv[])
{
	/*
	 * Vector Templates
	 * 
	 * A vector is a collection of objects, all of which
	 * have the same type. A vector is often referred to as
	 * a container because it "contains" other objects.
	 * 
	 * A vector is a class template. C++ has both class and 
	 * function templates. Templates are not themselves functions
	 * or classes. Instead, they can be thought of as instructions
	 * to the compiler for generating classes or functions. The process
	 * that the compiler uses to create classes or functions from templates
	 * is called instantiation. We specify which class to instantiate by
	 * supplying additional information. How we specify the information
	 * is always the same. We supply it inside a pair of angle brackets 
	 * following the template's name.
	 *
	 *
	 * Creating a Specified Number of Elements
	 *
	 * vector<int> ivec(10, -1);
	 *
	 *
	 * Value Initializaiton
	 *
	 * We can usually omit the value and supply only a size. In
	 * his case, the library creates a value-initialized element
	 * initializer for us. The value of the element initializer
	 * depends on the type of the elements stored in the vector.
	 * 
	 * There are two restrictions on this form of initialzation.
	 * The first is that some classes need an explicit initializer,
	 * which means such classes cannot default initialize. The second
	 * is we must use the direct form of initialization on the value-omited
	 * initialization.
	 *
	 */

	// vector is a template, not a type
	vector<int> ivec;				// ivec holds objects of type int
	vector<string> strvec;
	// for old-style of declarations for a vector of vectors, use vector<vector<int> >
	vector<vector<string>> file;	// vector whose elements are vectors

	// Because references are not objects, we can't have a vecor of references.
	// vector<int &> refvec;	// error: forming pointer to reference type "int &"


	/*
	 * Defineing and Initializing vectors
	 *
	 * We can supply a list of element values only by using using list initialization.
	 */
	vector<string> sv1;			// default initialization
	vector<string> sv2(sv1); 		// copy elements of v1 to v2
	vector<string> sv3 = sv2;		// same to above
	// vector<int> v4 = v3;		// error: type conflicts

	// list initializing: a list of zero or more initial element value
	vector<string> articles = {"a", "an", "the"};

	vector<int> nums(10);
	// vector<int> num2 = 2;	// error: cannot use copy form initialization for this

	for (auto n : nums)
		cout << n << endl;

	/* 
	 * The Different Initializers
	 *
	 * When we use parentheses, we are saying that the values we supply are to be
	 * used to construct the object.
	 * When we use curly braces, {...}, we're saying that, if possible, we want
	 * to list initialize the object. On the other hand, if there is no way to
	 * use the initializers to list initialize the object, then those values will
	 * be used to construct the object.
	 *
	 *
	 * Key Concept: vectors Grows Efficiently
	 *
	 * Because vectors grow efficiently, it is often unnecessary--and can result
	 * in poorer performance--to define a vector of a specific size. The exception
	 * to this rule is if all the elements actually need the same value.
	 *
	 *
	 * Operations
	 *
	 * We can compare two vectors only if we can compare the elements in those vectors.
	 *
	 * v.empty()
	 * v.size()
	 * v.push_back()
	 * v[n]
	 * ==, >, >=, <, <=...
	 *
	 * It is crucially important to understand that we may use the subscript operator
	 * to fetch only elements that actually exit.
	 * A good way to ensure that subscripts are in range is to avoid subcripting
	 * altogether by using a range for whenever possiable.
	 */

	// different initializers
	vector<int> v1(10);			// v1 has 10 elements whose value is 0 by default
	vector<int> v7{10};			// v7 has a element: 10
	vector<int> v2(v1);			// v2 has a copy of each element in v1
	vector<int> v3 = v1;		// v3 has a copy of each element in v1
	vector<int> v4(10, 1);		// v4 has 10 elements whose value is 1 
	vector<int> v5 = {10, 1};	// v5 has 2 elements: 10, 1
	vector<int> v6{10, 1};		// v6 has 2 elements: 10, 1

	// if list initialization isn't possible, the compiler looks for other ways to
	// initialize the object from the given values.
	vector<string> v8{10, "siso"};	// v8 has 10 elements whose value is "siso"
	vector<string> v9{10}; 			// v9 has 10 elements whose value is empty string by default

	// adding elements to a vector
	vector<int> intvec;
	for (int i = 0; i < 100; i++)
		intvec.push_back(i);

	// to access the size_type in vector
	vector<int>::size_type size;	// ok
	// vector::size_type;			// error

	vector<int> intvec2;
	// beacause the vector is a container that holds pointers, so if you
	// access the undefined objects, you are more likely to encounter segment fault.
	// cout << intvec2[0] << endl;	// segment fault: core dumped

	return 0;
}