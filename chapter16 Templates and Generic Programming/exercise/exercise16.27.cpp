#include <string>

using namespace std;


template <typename T> class Stack { };

void f1(Stack<char>);       // (a)

class Exercise 
{
    Stack<double> &rsd;     // (b)
    Stack<int> si;          // (c)
};

int main() 
{
    Stack<char> *sc;        // (d)
    f1(*sc);                // (e)
    int iObj = sizeof(Stack<string>); // (f)
}