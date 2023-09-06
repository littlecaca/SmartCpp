#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

/*
 * If a class defines its own swap, then the algorithm uses that
 * class-specific version. Otherwise, it uses the swap function
 * defined by the library.
 *
 * The std::swap algorithm: one copy and two assignments.
 *
 *
 * Note: Defining swap can be an important optimization for classes
 * that allocate resources.
 *
 *
 * Using swap in Assignment Operators
 *
 * The interesting thing about this technique is that it automatically
 * handles self assignment and is automatically exception safe.
 * (The only code that might throw is the new expression inside the
 * copy constructor, which will happen before we have changed the
 * left-hand operand)
 *
 */

class HasPtr {
    friend void swap(HasPtr &, HasPtr &);
    // other members
    std::string *ps;
    int i;

  public:
    HasPtr(const std::string &s = std::string(), int n = 0)
        : ps(new std::string(s)), i(n) {}
    HasPtr(const HasPtr &s) : ps(new auto(*s.ps)), i(s.i) {}

    HasPtr &operator=(HasPtr s);
    bool operator<(const HasPtr &s);
    ~HasPtr() {
        std::cout << "delete : " << *ps << std::endl;
        delete ps;
    }
    const std::string &getValue() const { return *ps; }
};

inline void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    std::cout << "swap : " << *lhs.ps << "<->" << *rhs.ps << std::endl;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

// Using swap in Assignment Operators (make use of the copy-constructor and swap)
HasPtr &HasPtr::operator=(HasPtr s) {
    std::cout << "assignment" << std::endl;
    swap(*this, s);
    return *this;
}

bool HasPtr::operator<(const HasPtr &s) {
    return i < s.i;
}

int main(int argc, char const *argv[]) {
    HasPtr p1("p1", 3), p2("p2", 2), p3("p3", 1);

    auto pv = std::vector<HasPtr>();
    pv.reserve(40);
    pv.push_back(p1);
    pv.push_back(p2);
    pv.push_back(p3);
    
    /*
     * std::sort does not always call std::swap
     *
     * https://stackoverflow.com/questions/14212701/stdsort-does-not-always-call-stdswap
     */
    std::sort(pv.begin(), pv.end());

    for (auto &p : pv) {
        std::cout << p.getValue() << std::endl;
    }
    return 0;
}
