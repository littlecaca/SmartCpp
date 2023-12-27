template <typename T> void f1(T, T);

template <typename T1, typename T2> void f2(T1, T2);


int main(int argc, char const *argv[])
{
    int i = 0, j = 42, *p1 = &i, *p2 = &j;
    const int *cp1 = p1, *cp2 = p2;

    f1(p1, p2);
    f2(p1, p2);
    f1(cp1, cp2);
    f2(cp1, cp2);
    /*
     * Because there are limited conversions, the arguments to such parameters
     * must have essentially the same type.
     */
    // f1(p1, cp1); // error
    // f1(cp1, p1); // error
    f1<const int *>(p1, cp1);
    f2(p1, cp1);
    return 0;
}
