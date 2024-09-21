namespace A
{
    namespace B
    {
        // one
        void func();
    }
}

namespace C
{
    // two
    void func();
    namespace D
    {
        using namespace A::B;
        void test()
        {
            func();
        }
    }
}