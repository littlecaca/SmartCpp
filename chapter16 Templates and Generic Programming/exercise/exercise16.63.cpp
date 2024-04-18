#include <cstring>
#include <vector>
#include <iostream>

// general version
template <class T> class Occur
{
    const std::vector<T> &mem;
public:
    explicit Occur(const std::vector<T> &m) : mem(m) {}
    size_t count(const T &tar) const;
};

template <class T>
size_t Occur<T>::count(const T &tar) const
{
    size_t res = 0;
    for (const T &i : mem)
    {
        if (i == tar)
            ++res;
    }
    return res;
}

// specialization for function count for Occur<const char *>
template <>
size_t Occur<const char *>::count(const char * const &tar) const
{
    size_t res = 0;
    for (const char *i : mem)
    {
        if (strcmp(i, tar) == 0)
            ++res;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    std::vector<int> v1{1, 2, 3, 4, 3, 2, 4};
    std::vector<const char *> v2{"tt", "ss", "qq", "tt", "tt"};
    std::vector<std::string> v3{"tt", "ss", "qq", "tt", "tt"};

    std::cout << Occur(v1).count(4) << std::endl;
    std::cout << Occur(v2).count("tt") << std::endl;
    std::cout << Occur(v3).count("tt") << std::endl;
    
    return 0;
}
