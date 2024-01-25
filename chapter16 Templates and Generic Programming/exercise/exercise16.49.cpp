

// f1
template <typename T> void f(T);

// f2
template <typename T> void f(const T*);

// g1
template <typename T> void g(T);

// g2
template <typename T> void g(T*);


int main(int argc, char const *argv[])
{
    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;
    g(42); g(p); g(ci); g(p2);
    f(42); f(p); f(ci); f(p2);
    /* code */
    return 0;
}
