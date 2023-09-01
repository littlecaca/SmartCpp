#include <string>
#include <iostream>

class HasPtr {
  public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) { }
    // Copy Constructor
    HasPtr(const HasPtr &);
    char getChar() { return ps->at(i++); }
    void setChar(char c) { (*ps)[i] = c; }

    HasPtr &operator=(const HasPtr &);
    // Destructor
    ~HasPtr() {
        delete ps;
        std::cout << "Obeject is going to be destroyed. " << std::endl;
     }
  private:
    std::string *ps;
    int i;
};

HasPtr::HasPtr(const HasPtr &ptr) : i(ptr.i) {
    ps = new std::string(*ptr.ps);
}

HasPtr &HasPtr::operator=(const HasPtr &ptr) {
    ps = new auto(*ptr.ps);
    i = ptr.i;
    return *this;
}

int main(int argc, char const *argv[])
{
    HasPtr ptr1("you are my hero");
    HasPtr ptr2 = ptr1;

    ptr2.setChar('g');
    std::cout << ptr2.getChar() << std::endl;
    std::cout << ptr2.getChar() << std::endl;
    std::cout << ptr2.getChar() << std::endl;
    std::cout << ptr1.getChar() << std::endl;
    return 0;
}
