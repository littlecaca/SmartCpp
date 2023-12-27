#include <iostream>
#include <string>
#include <vector>

struct X {
    X() { print("X()"); }
    X(const std::string &n) : name(n) { print("X()"); }
    // Copy Constructor
    X(const X &x1) : name(x1.name) { print("X(const X&)"); }
    // Copy-Assignment Operator
    X &operator=(const X &);
    // Destructor
    ~X() { print("~X()"); }

  private:
    std::string name = "unkown";
    void print(const std::string &msg) {
        std::cout << name << ": " << msg << std::endl;
    }
};

X &X::operator=(const X &x1) {
    name = x1.name;
    print("operator=(const X &)");
    return *this;
}

void test1(X x) {}

void test2(X &x) {}

int main(int argc, char const *argv[]) {
    std::cout << "Initializatoin" << std::string(20, '=') << std::endl;
    X x1("X1"), x2("X2"), x3("X3"), x4("X4");

    // Pass them as nonreference and reference parameters
    std::cout << "test1" << std::string(20, '=') << std::endl;
    test1(x1);

    std::cout << "test2" << std::string(20, '=') << std::endl;
    test2(x2);

    // Dynamically allocate them
    std::cout << "allocate" << std::string(20, '=') << std::endl;
    auto px1 = new X("x5");

    // Put them in containers
    std::cout << "add into vector" << std::string(20, '=') << std::endl;
    std::vector<X> vx;
    vx.push_back(*px1);

    // Copy Constructor
    std::cout << "copy constructor" << std::string(20, '=') << std::endl;
    X x6(*px1);

    // Copy Assignment
    std::cout << "Copy Assignment" << std::string(20, '=') << std::endl;
    x6 = x3;

    // delete
    std::cout << "delete the allocated obejct" << std::string(20, '=') << std::endl;
    delete px1;

    std::cout << "Done" << std::string(20, '=') << std::endl;

    return 0;
}
