class Base
{
public:
    void func() volatile;
    void func();
    void func2() noexcept(true);
    // noexcept is not part of function's type.
    // void func2() noexcept(false);

    void func3() &&;
    void func3() &;

    void func4() const;
    void func4();


};