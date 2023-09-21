#include <iostream>

class SmallInt {
    friend
    SmallInt operator+(const SmallInt &, const SmallInt &);

    size_t val;
  public:
    SmallInt(int = 0);
    operator int() const { return val; }
};

class YY {

};

YY f1(long double);
int f1(double);

int main(int argc, char const *argv[])
{
    SmallInt s1;
    // double d = s1 + 3.14;
    double d = static_cast<double>(s1) + 3.14;

    // int e = f1(12);
    return 0;
}
