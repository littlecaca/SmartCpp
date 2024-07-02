#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

template <class T, class Sequence>
class stack;

template <class T, class Sequence>
bool operator==(const stack<T, Sequence> &x,
                const stack<T, Sequence> &y)
{
    std::cout << "operator==()" << std::endl;
    return false;
}

/**
 * 在类模板中声明友元模板函数时，需要使用 friend 关键字并在尖括号内明确地指出模板参数。
 */
template <class T, class Sequence = std::deque<T>>
class stack
{
    // friend bool operator==<T>(const stack<T> &, const stack<T> &);
    friend bool operator==<>(const stack &, const stack &);
};


int main(int argc, char const *argv[])
{
    stack<int> s1, s2;
    s1 == s2;
    return 0;
}
