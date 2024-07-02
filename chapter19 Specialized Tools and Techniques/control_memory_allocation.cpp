#include <cstdlib>
#include <memory>
#include <iostream>

using namespace std;

/**
 * Control Memory Allocation
 * 
 * Warning
 * When we define the global operator new and operator delete
 * functions, we take over responsibility for all dynamic memory allocation.
 * These functions must be correct: They form a vital part of all processing in
 * the program.
 * 
 * Applications can define operator new and operator delete functions in the
 * global scope and/or as member functions. When the compiler sees a new or delete
 * expression, it looks for the corresponding operator function to call. If the object
 * being allocated (deallocated) has class type, the compiler first looks in the scope of
 * the class, including any base classes. If the class has a member operator new or
 * operator delete, that function is used by the new or delete expression.
 * 
 * Otherwise, the compiler looks for a matching function in the global scope. If the
 * compiler finds a user-defined version, it uses that function to execute the new or
 * delete expression. Otherwise, the standard library version is used.
 * 
 * 
 * The operator new and operator delete Interface
 * 
 * The library defines eight overloaded versions of operator new and delete
 * functions. The first four support the versions of new that can throw a bad_alloc
 * exception. The next four support nonthrowing versions of new.
 * 
 * // these versions might throw an exception
 * void *operator new(size_t); // allocate an object
 * void *operator new[](size_t); // allocate an array
 * void *operator delete(void*) noexcept; // free an object
 * void *operator delete[](void*) noexcept; // free an array
 * // versions that promise not to throw; see § 12.1.2 (p. 460)
 * void *operator new(size_t, nothrow_t&) noexcept;
 * void *operator new[](size_t, nothrow_t&) noexcept;
 * void *operator delete(void*, nothrow_t&) noexcept;
 * void *operator delete[](void*, nothrow_t&) noexcept;
 * 
 * 
 * The type nothrow_t is a struct defined in the new header. This type has no
 * members. The new header also defines a const object named nothrow, which users
 * can pass to signal they want the nonthrowing version of new (§ 12.1.2, p. 460). Like
 * destructors, an operator delete must not throw an exception (§ 18.1.1, p. 774).
 * When we overload these operators, we must specify that they will not throw, which
 * we do through the noexcept exception specifier (§ 18.1.4, p. 779).
 * 
 * An application can define its own version of any of these functions. If it does so, it
 * must define these functions in the global scope or as members of a class. When
 * defined as members of a class, these operator functions are implicitly static (§ 7.6, p.
 * 302). There is no need to declare them static explicitly, although it is legal to do
 * so. The member new and delete functions must be static because they are used
 * either before the object is constructed (operator new) or after it has been
 * destroyed (operator delete). There are, therefore, no member data for these
 * functions to manipulate.
 * 
 * When we define our own operator new function, we can define additional
 * parameters. A new expression that uses such functions must use the placement form
 * of new (§ 12.1.2, p. 460) to pass arguments to these additional parameters. Although
 * generally we may define our version of operator new to have whatever parameters
 * are needed, we may not define a function with the following form:
 * void *operator new(size_t, void*); // this version may not be redefined
 * This specific form is reserved for use by the library and may not be redefined.
 * 
 * 
 * Terminology: new Expression versus operator new Function
 * The library functions operator new and operator delete are
 * misleadingly named. Unlike other operator functions, such as operator=,
 * these functions do not overload the new or delete expressions. In fact, we
 * cannot redefine the behavior of the new and delete expressions.
 * A new expression always executes by calling an operator new function
 * to obtain memory and then constructing an object in that memory. A delete
 * expression always executes by destroying an object and then calling an
 * operator delete function to free the memory used by the object.
 * By providing our own definitions of the operator new and operator
 * delete functions, we can change how memory is allocated. However, we
 * cannot change this basic meaning of the new and delete operators.
 * 
 * 
 * The malloc and free Functions
 * 
 * 
 * 
 * Placement new Expressions
 * 
 * In effect, placement new allows us to construct an object at a specific, preallocated
 * memory address.
 * 
 * Note
 * When passed a single argument that is a pointer, a placement new
 * expression constructs an object but does not allocate memory.
 * 
 * Although in many ways using placement new is analogous to the construct
 * member of an allocator, there is one important difference. The pointer that we
 * pass to construct must point to space allocated by the same allocator object.
 * The pointer that we pass to placement new need not point to memory allocated by
 * operator new. Indeed, as we’ll see in § 19.6 (p. 851), the pointer passed to a
 * placement new expression need not even refer to dynamic memory.
 * 
 * 
 * 
 * Explicit Destructor Invocation
 * 
 * Just as placement new is analogous to using allocate, an explicit call to a
 * destructor is analogous to calling destroy. We call a destructor the same way we
 * call any other member function on an object or through a pointer or reference to an
 * object:
 * string *sp = new string("a value"); // allocate and initialize a string
 * sp->~string();
 * 
 * Like calling destroy, calling a destructor cleans up the given object but does not
 * free the space in which that object resides. We can reuse the space if desired.
 * 
 * Note
 * Calling a destructor destroys an object but does not free the memory.
 * 
 * 
 * 
 * Run-Time Type Identification
 * 
 * Run-time type identification (RTTI) is provided through two operators:
 * • The typeid operator, which returns the type of a given expression
 * • The dynamic_cast operator, which safely converts a pointer or reference to a
 *   base type into a pointer or reference to a derived type.
 * 
 * When applied to pointers or references to types that have virtual functions, these
 * operators use the dynamic type (§ 15.2.3, p. 601) of the object to which the pointer
 * or reference is bound.
 * 
 * However, it is not always possible to define a virtual. If we cannot use a virtual, we
 * can use one of the RTTI operators. On the other hand, using these operators is more
 * error-prone than using virtual member functions: The programmer must know to
 * which type the object should be cast and must check that the cast was performed
 * successfully.
 * 
 * Warning
 * RTTI should be used with caution. When possible, it is better to define a
 * virtual function rather than to take over managing the types directly.
 * 
 */

void *operator new(size_t size)
{
    if (void *mem = malloc(size))
        return mem;
    else
        throw bad_alloc();
}

void *operator new(size_t size, nothrow_t &) 
{
    std::cout << "operator new" << std::endl;
    return malloc(size);
}

void operator delete(void *mem) noexcept { free(mem); }


int main(int argc, char const *argv[])
{
    allocator<int> allo;
    
    int *p = allo.allocate(12 * sizeof(int));
    allo.construct(p, 12);
    allo.destroy(p);
    allo.deallocate(p, 12);
    
    return 0;
}
