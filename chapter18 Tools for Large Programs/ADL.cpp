/**
 * 结论
 * 
 * 当前作用域与其祖先作用域中相同的名字只有最近的作用域会加入candidates
 * 参数类及其基类所在的作用域中的函数都会被加入candidates
 * 
 */


namespace A1
{
    namespace A2
    {
        namespace A4
        {
            class Base
            {};
        }
        
        namespace A3
        {
            class Derived : A4::Base
            {};
            // namespace A3
            void f2(Derived);
        }
        // namespace A2
        void f2(A3::Derived);

        namespace A4
        {
            // namespace A4
            // void f2(A3::Derived);
        }

    }
    // namespace A
    // void f2(A2::A3::Derived);


    namespace A2
    {
        void f1(A3::Derived b)
        {
            // f2(b);
        }
    }

    void f1(A2::A3::Derived d)
    {
        f2(d);
    }
}

// global
// void f2(A::A2::A3::Derived);

int main(int argc, char const *argv[])
{
    A1::A2::A3::Derived b;
    // f2(b);
    return 0;
}
