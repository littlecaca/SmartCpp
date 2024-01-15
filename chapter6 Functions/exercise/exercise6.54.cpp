#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int f1(int i, int j) {
    return 0;
}
vector<decltype(f1) *> vf{};
vector<int (*)(int, int)> vf2{};


int add(int i, int j) {
    return i + j;
}
int subtract(int i, int j) {
    return i - j;
}
int multiply(int i, int j) {
    return i * j;
}
int divide(int i, int j) {
    return i / j;
}

int main(int argc, char const *argv[])
{
 
    // vector<int (int, int)> vf3{};    // error: the function type is not allowed here
    
    vf = {add, subtract, multiply, divide}; 
    
    for (auto f : vf) {
        cout << f(4, 7) << endl;
    }
    
    return 0;
}


