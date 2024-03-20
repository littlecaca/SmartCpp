template <typename... T>
struct Foo;

template <typename T1>
struct Foo<T1> {};

template <typename T1, typename T2>
struct Foo<T1,T2> {};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
