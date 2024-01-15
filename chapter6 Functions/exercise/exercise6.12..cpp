#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void reset(int &i) {
    i = 0;
}

void swap(int &i1, int &i2) {
    int temp = i1;
    i1 = i2;
    i2 = temp;
}


int main(int argc, char const *argv[])
{
    int n = 3, m = 4;
    reset(n);
    swap(n, m);
    cout << n << " " << m << endl;
    /* code *//* code */
    return 0;
}
