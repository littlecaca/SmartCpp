#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

template <class T> std::string debug_rep(const T &t)
{
    std::ostringstream ret;
    ret << t;
    return ret.str();
}

// Overloaded tempalte function
template <class T> std::string debug_rep(T *t)
{
    return debug_rep(*t);
}

template <>
std::string debug_rep(const char *t)
{
    return debug_rep(std::string(t));
}

template <>
std::string debug_rep(char *t)
{
    return debug_rep(std::string(t));
}

int main(int argc, char const *argv[])
{
    char word[] = "this";
    char *w1 = word;
    const char *w2 = "I am";
    std::string s = "Mama";
    std::string *w3 = &s;
    std::cout << debug_rep(w1) << std::endl;
    std::cout << debug_rep(w2) << std::endl;
    std::cout << debug_rep("I am just a boy") << std::endl;
    std::cout << debug_rep(w3) << std::endl;

    return 0;
}
