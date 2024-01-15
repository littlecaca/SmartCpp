#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    /* code */
    int i = 10;
    auto f = [&i] () -> bool {
        bool flag = i > 0 ? true : false;
        while (i > 0)
            --i;
        return flag;
    };

    cout << (f() ? "yes i > 0" : "no i < 0") << endl;
    return 0;
}
