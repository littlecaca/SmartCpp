#include <iostream>
#include <atomic>
#include <string>

using namespace std;

template <typename T>
void check(std::atomic<T> &a)
{
    // if (a.is_lock_free())
    // {
    //     cout << "yes" << endl;
    // }
    // else
    // {
    //     cout << "no" << endl;
    // }

    if (a.is_always_lock_free)
    {
        cout << "always yes" << endl;
    }
    else
    {
        cout << "always no" << endl;
    }
}

struct Foo
{
    double a;
    int b;
};

int main(int argc, char const *argv[])
{
    std::atomic<int> i;
    std::atomic<Foo> i2;
    check(i);
    check(i2);
    return 0;
}
