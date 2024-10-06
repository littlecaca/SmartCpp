class Base
{
public:
    void func1(int, int)        // _ZN4Base5func1Eii
    {

    }
    
    void func2(double, double)  // _ZN4Base5func2Edd
    {

    }
};

int main(int argc, char const *argv[])
{
    Base foo;

    foo.func1(1, 23);
    foo.func2(1.2, 23.2);
    return 0;
}
