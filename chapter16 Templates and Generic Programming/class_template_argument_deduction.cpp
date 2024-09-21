#include <iostream>

using namespace std;

template <typename T>
class Base
{
public:
    Base(T i)
    {
        cout << i << endl;
    }
};

int main(int argc, char const *argv[])
{
    Base b(12);
    // Base b(12);
    return 0;
}
