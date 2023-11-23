#include <iostream>

template <typename T>
class T1
{
public:
    void print(T val)
    {
        std::cout << val << std::endl;
    }
    template <typename TT>
    void pp(TT val)
    {
        std::cout << val << std::endl;
    }
};
