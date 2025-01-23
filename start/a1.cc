#include <atomic>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <type_traits>

using namespace std;

template <typename T>
constexpr remove_reference<T> &&move(T &&obj) noexcept
{
    return static_cast<remove_reference<T>&&>(obj);
}

template <class T>
void f(T &)
{
    return;
}


int main(int argc, char const *argv[])
{
    // atomic<int> value = 31;
    // cout << value << endl;
    int x;
    const int y = 12;
    f(y);

    

    std::move(x);
    return 0;
}
