#include <iostream>


/*
 * Namespaces provide a much more controlled mechanism for preventing name
 * collisions.
 *
 *
 * Namespace Definitions
 *
 * As with any name, a namespace name must be unique within the scope in which
 * the namespace is defined. Namespaces may be defined at global scope or inside
 * another namespace. They may not be defined inside a function or a class.
 *
 * Note
 * A namespace scope does not end with a semicolon.
 *
 *
 * Each Namespace Is a Scope
 *
 * As is the case for any scope, each name in a namespace must refer to a unique entity
 * within that namespace. Because different namespaces introduce different scopes,
 * different namespaces may have members with the same name.
 *
 * Names defined in a namespace may be accessed directly by other members of the
 * namespace, including scopes nested within those members. Code outside the
 * namespace must indicate the namespace in which the name is defined.
 *
 *
 * Namespaces Can Be Discontiguous
 *
 * A namespace can be organized in the same way that we manage our own class
 * and function definitions:
 * • Namespace members that define classes, and declarations for the functions and
 *   objects that are part of the class interface, can be put into header files. These
 *   headers can be included by files that use those namespace members.
 * • The definitions of namespace members can be put in separate source files
 *
 * Best Practices
 * Namespaces that define multiple, unrelated types should use separate files to
 * represent each type (or each collection of related types) that the namespace
 * defines.
 *
 *
 * Defining the Primer Namespace
 *
 * A user of one class need not compile names related to the
 * others. We can hide the implementations from our users, while allowing the files
 * Sales_data.cc and user.cc to be compiled and linked into one program without
 * causing any compile-time or link-time errors. Developers of the library can work
 * independently on the implementation of each type.
 *
 *
 * Defining Namespace Members
 *
 * It is also possible to define a namespace member outside its namespace definition.
 * The namespace declaration of the name must be in scope, and the definition must
 * specify the namespace to which the name belongs.
 *
 * As with class members defined outside a class, once the fully qualified name is seen,
 * we are in the scope of the namespace. Inside the cplusplus_primer namespace,
 * we can use other namespace member names without qualification.
 *
 * Although a namespace member can be defined outside its namespace, such
 * definitions must appear in an enclosing namespace. That is, we can define the
 * Sales_data operator+ inside the cplusplus_primer namespace or at global
 * scope. We cannot define this operator in an unrelated namespace.
 *
 *
 * Template Specializations
 *
 * Template specializations must be defined in the same namespace that contains the
 * original template (§ 16.5, p. 709). As with any other namespace name, so long as we
 * have declared the specialization inside the namespace, we can define it outside the
 * namespace.
 *
 *
 * The Global Namespace
 *
 * Names defined at global scope (i.e., names declared outside any class, function, or
 * namespace) are defined inside the global namespace. The global namespace is
 * implicitly declared and exists in every program.
 *
 * The scope operator can be used to refer to members of the global namespace.
 * Because the global namespace is implicit, it does not have a name; the notation
 * ::member_name
 * refers to a member of the global namespace.
 *
 *
 * Nested Namespaces
 *
 * A nested namespace is a namespace defined inside another namespace.
 *
 * Nested namespace names follow the normal rules: Names declared in
 * an inner namespace hide declarations of the same name in an outer namespace.
 * Code in the outer parts of the enclosing namespace may refer to a name in a nested
 * namespace only through its qualified name.
 *
 *
 * Inline Namespaces
 *
 * Unlike ordinary nested namespaces, names in an inline namespace can
 * be used as if they were direct members of the enclosing namespace.
 *
 * An inline namespace is defined by preceding the keyword namespace with the
 * keyword inline.
 *
 *
 * Unnamed Namespaces
 *
 * An unnamed namespace is the keyword namespace followed immediately by a
 * block of declarations delimited by curly braces. Variables defined in an unnamed
 * namespace have static lifetime: They are created before their first use and destroyed
 * when the program ends.
 *
 * An unnamed namespace may be discontiguous within a given file but does not span
 * files. Each file has its own unnamed namespace. If two files contain unnamed
 * namespaces, those namespaces are unrelated. Both unnamed namespaces can define
 * the same name; those definitions would refer to different entities. If a header defines
 * an unnamed namespace, the names in that namespace define different entities local to
 * each file that includes the header.
 *
 * Note
 * Unlike other namespaces, an unnamed namespace is local to a particular file
 * and never spans multiple files.
 *
 * Names defined in an unnamed namespace are used directly; after all, there is no
 * namespace name with which to qualify them. It is not possible to use the scope
 * operator to refer to members of unnamed namespaces.
 *
 * Unnamed Namespaces Replace File Statics
 *
 * Prior to the introduction of namespaces, programs declared names as static to
 * make them local to a file. The use of file statics is inherited from C. In C, a global
 * entity declared static is invisible outside the file in which it is declared.
 *
 * Warning
 * The use of file static declarations is deprecated by the C++ standard.
 * File statics should be avoided and unnamed namespaces used instead.
 *
 *
 * Using Namespace Members
 *
 * Namespace Aliases
 * A namespace alias can be used to associate a shorter synonym with a namespace
 * name.
 *      namespace primer = cplusplus_primer;
 * A namespace alias can also refer to a nested namespace:
 *      namespace Qlib = cplusplus_primer::QueryLib;
 *
 * Note
 * A namespace can have many synonyms, or aliases. All the aliases and the
 * original namespace name can be used interchangeably.
 *
 * using Declarations: A Recap
 *
 * Names introduced in a using declaration obey normal scope rules: They are visible
 * from the point of the using declaration to the end of the scope in which the
 * declaration appears. Entities with the same name defined in an outer scope are
 * hidden. The unqualified name may be used only within the scope in which it is
 * declared and in scopes nested within that scope. Once the scope ends, the fully
 * qualified name must be used.
 *
 * A using declaration can appear in global, local, namespace, or class scope. In class
 * scope, such declarations may only refer to a base class member (§ 15.5, p. 615).
 *
 *
 * using Directives
 *
 * A using directive may appear in global, local, or
 * namespace scope. It may not appear in a class scope.
 *
 * Warning
 * Providing a using directive for namespaces, such as std, that our
 * application does not control reintroduces all the name collision problems
 * inherent in using multiple libraries.
 *
 *
 * using Directives and Scope
 *
 * In general, a namespace
 * might include definitions that cannot appear in a local scope. As a consequence, a
 * using directive is treated as if it appeared in the nearest enclosing namespace scope.
 * In the simplest case, assume we have a namespace A and a function f, both
 * defined at global scope. If f has a using directive for A, then in f it will be as if the
 * names in A appeared in the global scope prior to the definition of f.
 *
 * When a namespace is injected into an enclosing scope, it is possible for names in
 * the namespace to conflict with other names defined in that (enclosing) scope. For
 * example, inside manip, the blip member j conflicts with the global object named j.
 * Such conflicts are permitted, but to use the name, we must explicitly indicate which
 * version is wanted. Any unqualified use of j within manip is ambiguous.
 *
 *
 * Headers and using Declarations or Directives
 *
 * Caution: Avoid using Directives
 * 
 * Ordinarily, headers should define only
 * the names that are part of its interface, not names used in its own implementation. As
 * a result, header files should not contain using directives or using declarations
 * except inside functions or namespaces (§ 3.1, p. 83).
 *
 * it can introduce its own problems. If an application uses many libraries, and if the
 * names within these libraries are made visible with using directives, then we are
 * back to square one, and the global namespace pollution problem reappears.
 *
 * Moreover, it is possible that a working program will fail to compile when a new
 * version of the library is introduced. This problem can arise if a new version
 * introduces a name that conflicts with a name that the application is using.
 *
 * Another problem is that ambiguity errors caused by using directives are
 * detected only at the point of use. This late detection means that conflicts can
 * arise long after introducing a particular library. If the program begins using a new
 * part of the library, previously undetected collisions may arise.
 * 
 * Tip
 * One place where using directives are useful is in the implementation
 * files of the namespace itself.
 * 
 * 
 */

inline namespace FifthEd
{
    // namespace for the code from the Primer Fifth Edition
}

namespace FifthEd
{ // implicitly inline
    class Query_base
    {
        /* ... */
    };
    // other Query-related declarations
}

void f(){};

namespace Myown
{
    namespace subname1
    {
        void f(){};
        void f2(int);
    }
    namespace subname2
    {
        /**
         * cannot define or redeclare 'f2' 
         * here because namespace 'subname2' does not enclose namespace 'subname1'
        */
        // void Myown::subname1::f2(int a)
        // {}
        void f(){};
    }
    void f(){};
    // ok
    void subname1::f2(int)
    {}
}

int main(int argc, char const *argv[])
{

    return 0;
}

namespace Myown
{
    // namespace can be discontiguous
}

namespace blip
{
    int i = 16, j = 15, k = 23;
    // other declarations
}
int j = 0; // ok: j inside blip is hidden inside a namespace
// int z = 0;
namespace deeper
{
    void f() {}
    namespace de
    {
        int z = 13;
        namespace blip2
        {
            void f(int i) {}
            int z = 12;
        }
    }
    // int z = 21;
    namespace deeperer
    {
        // int j = 0;
        void manip()
        {
            using namespace blip; // clash between ::j and blip::j
            using namespace de::blip2;
            // using directive; the names in blip are ''added'' to the global scope
            // detected only if j is used
            ++i; // sets blip::i to 17
            // ++j;                             // error ambiguous: global j or blip::j?

            ++::j;      // ok: sets global j to 1
            ++blip::j;  // ok: sets blip::j to 16
            int k = 97; // local k hides blip::k
            ++k;        // sets local k to 98
            ++z;
            f();
        }
    }
}


// using blip::j;       // the name conflicts will be detected in compile time
using namespace blip;   // the name conflicts will not be reported until using the crashing names.
// int my = j;


using std::cout;
class Base
{
protected:
    using type = int;
};

class Test : Base
{
public:
    /**
     * In class scope, using declaration can only refer to a base class member
    */
    // using std::cout;

    using Base::type;
};


void f3()
{
    using ::Test;
}