#include <memory>
#include <iostream>
#include <vector>

using namespace std;

/*
 * Explicit Instantiation
 * 
 * The fact that instantiations are generated when a template
 * is used means that the same instantiation may appear in multiple
 * objects files. When two or more separately compiled source files
 * use the same template with the same template arguments, there is an
 * instantiation of that template in each of those files.
 * 
 * Under the new standard, we can avoid this overhead through an explicit
 * instantiation. An explicit instantiation has the form:
 * 
 * extern template declaration; // instantiation declaration
 * tempalte declaration;        // instantiation definition
 * 
 * for example:
 * extern template Blob<string>;                    // explicit instantiation declaration
 * template int compare(const int &, const int &);  // explicit instantiation definition
 * 
 * When the compiler sees an extern template declaration, it will not 
 * generate code for that instantiation in that file. But there must be
 * exactly one definition for that instantiation elsewhere.
 * 
 * Warning
 * There must be an explicit instantiation definition somewhere in the program
 * for every instantiation declaration.
 * 
 * 
 * 
 * Instantition Definition Instantiate All Members
 * 
 * Even if we do not use a member, that member will be
 * instantiated. Consequently, we can use explicit instantiation only for types that can be
 * used with all the members of that template.
 * Note
 * An instantiation definition can be used only for types that can be used with
 * every member function of a class template.
 * 
 * 
 * 
 * Efficiency and Flexibility
 * 
 * The library smart pointer types (shared_ptr and unique_ptr) offer a good illustration of design
 * choices faced by designers of templates.
 * 
 * The difference in how the deleter is handled is incidental to the functionality of
 * these classes.
 * This difference in implementation strategy may have important performance impacts.
 * 
 * Binding the Deleter at Run Time
 * 
 * The shared_ptr destructor must include a statement such as
 * 
 * // value of del known only at run time; call through a pointer
 * del ? del(p) : delete p; // del(p) requires run-time jump to del's location
 * 
 * Binding the Deleter at Compile Time
 * 
 * // del bound at compile time; direct call to the deleter is instantiated
 * del(p); // no run-time overhead
 * 
 * The type of del is either the default deleter type or a user-supplied type. It doesn’t
 * matter; either way the code that will be executed is known at compile time.
 * 
 * 
 */

int main(int argc, char const *argv[])
{
    unique_ptr<vector<int>> u;
    shared_ptr<vector<int>> s;
    weak_ptr<vector<int>> w;
    
    return 0;
}
