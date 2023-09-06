#include <iostream>
#include <string>

class HasPtr {
    std::string *ps;
    int i;
    std::size_t *use;

  public:
    // Defualt constructor
    HasPtr(const std::string &s = std::string())
        : ps(new auto(s)), i(0), use(new std::size_t(1)) {}
    // Copy constructor
    HasPtr(const HasPtr &ptr) : ps(new auto(*ptr.ps)), i(ptr.i), use(ptr.use) {
        ++*use;
    }
    // Copy assignment operator
    HasPtr &operator=(const HasPtr &);
    // Destructor
    ~HasPtr();
    
    std::string getName() const { return *ps + " : " + std::to_string(i); }
};

HasPtr &HasPtr::operator=(const HasPtr &ptr) {
    ++*ptr.use;
    if (--*use == 0) {
        delete ps;
        delete use;
    }
    ps = ptr.ps;
    i = ptr.i;
    use = ptr.use;
    return *this;
}

HasPtr::~HasPtr() {
    if (--*use == 0) {
        delete ps;
        delete use;
    }
}

int main(int argc, char const *argv[]) {
    /* code */


    return 0;
}
