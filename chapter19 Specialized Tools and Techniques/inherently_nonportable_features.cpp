/**
 * Inherently Nonportable Features
 *
 * To support low-level programming, C++ defines some features that are inherently
 * nonportable.
 *
 * A nonportable feature is one that is machine specific. Programs that
 * use nonportable features often require reprogramming when they are moved from one
 * machine to another.
 *
 *
 * Bit-fields
 *
 * A class can define a (nonstatic) data member as a bit-field. A bit-field holds a
 * specified number of bits. Bit-fields are normally used when a program needs to pass
 * binary data to another program or to a hardware device.
 *
 * Note
 * The memory layout of a bit-field is machine dependent.
 *
 * The address-of operator (&) cannot be applied to a bit-field, so there can be no
 * pointers referring to class bit-fields.
 *
 *
 * Warning
 * Ordinarily it is best to make a bit-field an unsigned type. The behavior of
 * bit-fields stored in a signed type is implementation defined.
 *
 *
 * Using Bit-fields
 *
 *
 *
 * volatile Qualifier
 *
 * Warning
 * The precise meaning of volatile is inherently machine dependent and can
 * be understood only by reading the compiler documentation. Programs that
 * use volatile usually must be changed when they are moved to new
 * machines or compilers.
 *
 * The volatile keyword is a directive to the compiler that it
 * should not perform optimizations on such objects.
 *
 * There is no interaction between the const and volatile type qualifiers. A type can
 * be both const and volatile, in which case it has the properties of both.
 *
 * In the same way that a class may define const member functions, it can also
 * define member functions as volatile. Only volatile member functions may be
 * called on volatile objects.
 *
 *
 * Synthesized Copy Does Not Apply to volatile Objects
 *
 * One important difference between the treatment of const and volatile is that the
 * synthesized copy/move and assignment operators cannot be used to initialize or assign
 * from a volatile object. The synthesized members take parameters that are
 * references to (nonvolatile) const, and we cannot bind a nonvolatile reference
 * to a volatile object.
 *
 * If a class wants to allow volatile objects to be copied, moved, or assigned, it
 * must define its own versions of the copy or move operation.
 *
 *
 *
 * Linkage Directives: extern "C"
 *
 * C++ programs sometimes need to call functions written in another programming
 * language. Most often, that other language is C.
 *
 * As with any function, that declaration
 * must specify the return type and parameter list. The compiler checks calls to functions
 * written in another language in the same way that it handles ordinary C++ functions.
 * However, the compiler typically must generate different code to call functions written
 * in other languages. C++ uses linkage directives to indicate the language used for
 * any non-C++ function.
 *
 * Note
 * Mixing C++ with code written in any other language, including C, requires
 * access to a compiler for that language that is compatible with your C++
 * compiler.
 *
 *
 * Declaring a Non-C++ Function
 *
 * A linkage directive can have one of two forms: single or compound. Linkage directives
 * may not appear inside a class or function definition. The same linkage directive must
 * appear on every declaration of a function.
 * 
 * 
 * Linkage Directives and Headers
 * 
 * The multiple-declaration form can be applied to an entire header file.
 * 
 * 
 * Note
 * The functions that C++ inherits from the C library are permitted to be
 * defined as C functions but are not required to be C functions—it’s up to each
 * C++ implementation to decide whether to implement the C library functions
 * in C or C++.
 * 
 * 
 * Pointers to extern "C" Functions
 * 
 * The language in which a function is written is part of its type. Hence, every
 * declaration of a function defined with a linkage directive must use the same linkage
 * directive. Moreover, pointers to functions written in other languages must be declared
 * with the same linkage directive as the function itself.
 * 
 * A pointer to a C function does not have the same type as a pointer to a C++
 * function. A pointer to a C function cannot be initialized or be assigned to point to a
 * C++ function (and vice versa). As with any other type mismatch, it is an error to try
 * to assign two pointers with different linkage directives
 * 
 * Warning
 * Some C++ compilers may accept the preceding assignment as a language
 * extension, even though, strictly speaking, it is illegal.
 * 
 * 
 * Linkage Directives Apply to the Entire Declaration
 * 
 * When we use a linkage directive, it applies to the function and any function pointers
 * used as the return type or as a parameter type.
 * 
 * Because a linkage directive applies to all the functions in a declaration, we must use
 * a type alias (§ 2.5.1, p. 67) if we wish to pass a pointer to a C function to a C++
 * function.
 * 
 * 
 * Exporting Our C++ Functions to Other Languages
 * 
 * By using the linkage directive on a function definition, we can make a C++ function
 * available to a program written in another language.
 * 
 * It is worth noting that the parameter and return types in functions that are shared
 * across languages are often constrained. For example, we can almost surely not write a
 * function that passes objects of a (nontrivial) C++ class to a C program. The C
 * program won’t know about the constructors, destructors, or other class-specific
 * operations.
 * 
 * 
 * 
 * Preprocessor Support for Linking to C
 * To allow the same source file to be compiled under either C or C++, the
 * preprocessor defines _ _cplusplus (two underscores) when we compile
 * C++. Using this variable, we can conditionally include code when we are
 * compiling C++
 * 
 * 
 * Overloaded Functions and Linkage Directives
 * 
 * The interaction between linkage directives and function overloading depends on the
 * target language. If the language supports overloaded functions, then it is likely that a
 * compiler that implements linkage directives for that language would also support
 * overloading of these functions from C++.
 * 
 * If one function among a set of overloaded functions is a C function, the other
 * functions must all be C++ functions.
 */

typedef unsigned int Bit;

class File
{
    Bit mode : 2;
    Bit modified : 1;
    Bit prot_owner : 3;
    Bit prot_group : 3; // prot_group has 3 bits
    Bit prot_world : 3; // prot_world has 3 bits
    // operations and data members of File
public:
    // file modes specified as octal literals; see § 2.1.3 (p. 38)
    enum modes
    {
        READ = 01,
        WRITE = 02,
        EXECUTE = 03
    };
    File &open(modes);
    void close();
    void write();
    bool isRead() const;
    void setWrite();
};

File &File::open(File::modes m)
{
    mode |= READ; // set the READ bit by default
    // other processing
    if (m & WRITE) // if opening READ and WRITE
        // processing to open the file in read/write mode
        ;
    return *this;
}

inline bool File::isRead() const { return mode & READ; }
inline void File::setWrite() { mode |= WRITE; }

class Foo
{
public:
    Foo(const volatile Foo &); // copy from a volatile object
    // assign from a volatile object to a nonvolatile object
    Foo &operator=(volatile const Foo &);
    // assign from a volatile object to a volatile object
    Foo &operator=(volatile const Foo &) volatile;
    // remainder of class Foo
};

// illustrative linkage directives that might appear in the C++ header <cstring>
// single-statement linkage directive
extern "C" size_t strlen(const char *);
// compound-statement linkage directive
extern "C"
{
    int strcmp(const char *, const char *);
    char *strcat(char *, const char *);
}

extern "C"
{
    #include <stdio.h>
}

extern "C" void (*pf)(int);

// f1 is a C function; its parameter is a pointer to a C function
extern "C" void f1(void(*)(int));

// FC is a pointer to a C function
extern "C" typedef void FC(int);
// f2 is a C++ function with a parameter that is a pointer to a C function
void f2(FC *);

// the calc function can be called from C programs
extern "C" double calc(double dparm) { /* ... */ }

// error: two extern "C" functions with the same name
// extern "C" void print(const char*);
// extern "C" void print(int);

int main(int argc, char const *argv[])
{
    volatile const int i = 10;

    // pf points to a C function that returns void and takes an int
    return 0;
}
