#include <string>
#include <iostream>

class HasPtr {
  public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) { }
    // Copy Constructor
    HasPtr(const HasPtr &);
    // Copy Assignment
    HasPtr &operator=(const HasPtr &);
    // Destructor
    ~HasPtr() { delete ps; }

    char getChar() { return ps->at(i++); }
    void setChar(char c) { (*ps)[i] = c; }
  private:
    std::string *ps;
    int i;
};

HasPtr::HasPtr(const HasPtr &ptr) : i(ptr.i) {
    ps = new std::string(*ptr.ps);
}

HasPtr &HasPtr::operator=(const HasPtr &ptr) {
    // !!!!!!!!!!!!!!!!!
    // The following code's order is wrong, we should consider that
    // the self assignment.
    // delete ps;   
    // ps = new std::string(*ptr.ps);
    auto newp = new std::string(*ptr.ps);
    delete ps;
    ps = newp;
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
