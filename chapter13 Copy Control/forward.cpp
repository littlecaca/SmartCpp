#include <iostream>
#include <utility>
#include <string>

using namespace std;

template <typename T>
constexpr T &&MyForward(T &&arg)
{
    return static_cast<T &&>(arg);
}


int main(int argc, char const *argv[])
{
    string s1 = "nihao";
    auto s2 = MyForward(s1);
    auto s3 = MyForward(string("213"));

    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    return 0;
}
