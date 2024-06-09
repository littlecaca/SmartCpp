class Base
{
public:
    Base() {}
    Base(const Base &) {}
    Base(int) {}
};

class D1 : public Base
{
public:
    D1() {}
    D1(const D1 &d) : Base(d) {}
    D1(int a) : Base(a) {}
};

int main(int argc, char const *argv[])
{
    D1 d(121);
    return 0;
}
