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
	vector<string> v1;			// default initialization
	vector<string> v2(v1); 		// copy elements of v1 to v2
	vector<string> v3 = v2;		// same to above
	// vector<int> v4 = v3;		// error: type conflicts

	// list initializing: a list of zero or more initial element value
	vector<string> articles = {"a", "an", "the"};

	cout << "exit" << endl;
	return 0;
}