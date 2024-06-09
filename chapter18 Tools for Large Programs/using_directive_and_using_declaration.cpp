/*
 * The using directive and using declaration have 3 main differences:
 * 1. The using directive import all name in that namespace, and the latter import just one.
 * 2. The using directive does not lead to ambiguous name errors in compile time util you using
 *    the them.
 * 3. The using directive will import names as if they are defined in the enclosing scope of the
 *    namespace and the using directive, and the using declaration import the name to the current scope.
 */

namespace A
{
    namespace B
    {
        int z = 1;
    }
}

int z = 2;

int main(int argc, char const *argv[])
{
    /**
     * the namepsace A::B is in the global namespace,
     * so, int z == 1 will be treated as declared in the global scope.
    */ 
    using namespace A::B;
    // ++z;
    return 0;
}
