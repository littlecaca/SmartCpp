#include <iostream>

// char *
int func(char *)
{
    return 0;
}

// int
int func(int)
{
    return 0;
}

struct Base
{
    int a;
    int b;
};


int main(int argc, char const *argv[])
{
    void *pv = 0;
    int a = 12;
    a = {21};

    Base b = {12, 12};
    b = {123, 1};
    
    // char *pc = pv;
    char *pc = static_cast<char *>(pv);
    func(NULL);
    func(nullptr);
    return 0;
}
