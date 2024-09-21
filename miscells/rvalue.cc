#include <iostream>
#include <utility>

using namespace std;

int main(int argc, char const *argv[])
{
    const int &a = (1 + 2);
    // int &a = 1;
    // int *a = 12;
    int &&vv = 12 + 213;
    int rval = 12;
    int c = 21, d = 1321, asd =2131, sd= 213, dsa= 312131, ipj = 321321;
    // int &&b = std::move(rval);
    cout << vv << endl;
    return 0;
}
