#include <iostream>

class Foo
{
public:
    int Get()
    {
        return a * b;
    }

private:
    int a;
    int b;
};

inline Foo f1;
