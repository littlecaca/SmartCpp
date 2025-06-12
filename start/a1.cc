#include <string>
#include <cstring>
#include <iostream>
#include <string.h>

using namespace std;

template <class Ty>
bool mymax(Ty left, Ty right) {
    return left < right ? right : left;
}

int main()
{
    int n = 12;
    switch (n) {
    case 12:
        cout << "yes" << endl;
    default:
        cout << "no" << endl;
    }
    
    std::string text;
    std::string t2;

    memmove(text.data(), t2.data(), t2.size());
    
    int a = 1;
    float b = 2;
    return 0;
}
