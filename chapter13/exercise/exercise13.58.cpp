#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

class Foo {
    std::vector<std::string> vs;
  public:
    Foo sorted() const &;
    Foo sorted() &&;
};

// Foo Foo::sorted() const & {
//     std::cout << "sorted" << std::endl;
//     Foo ret(*this);
//     return ret.sorted();
// }

Foo Foo::sorted() const & {
    std::cout << "lvalue sorted" << std::endl;
    return Foo(*this).sorted();
}

Foo Foo::sorted() && {
    std::cout << "rvalue sorted" << std::endl;
    std::sort(vs.begin(), vs.end());
    return *this;
}


int main(int argc, char const *argv[])
{
    Foo f1;
    f1.sorted();
    return 0;
}
