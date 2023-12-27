/*
 * Copy elision
 *
 * Copy elision is a compiler optimization technique that allows 
 * the compiler to remove unnecessary copying of objects.
 * 
 * Unlike other types of optimization, copy elision is exempt from the “as-if” rule. 
 * That is, copy elision is allowed to elide the copy constructor even if 
 * the copy constructor has side effects (such as printing text to the console)! 
 * 
 * This is why copy constructors should not have side effects other than copying 
 * -- if the compiler elides the call to the copy constructor, 
 * the side effects won’t execute, and the observable behavior of the program will change!
 * 
 * 
 * The copy elision will happens in such cases:
 * 1.Unnecessary Copy
 *      Something s{ Something{}; }
 * 2.Copy elision in pass by value and return by value
 * 
 * 
 * 
 * Copy elision errata
 *
 * Prior to C++17, copy elision was strictly an optional optimization 
 * that compilers could make. In C++17, copy elision became mandatory in some cases.
 * In optional elision cases, an accessible copy constructor 
 * must be available (e.g. not deleted), even if the actual call 
 * to the copy constructor is elided. In mandatory elision cases, 
 * an accessible copy constructor need not be available.
 */