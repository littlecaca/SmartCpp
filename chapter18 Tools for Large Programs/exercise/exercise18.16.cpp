namespace Exercise
{
    int ivar = 0;
    double dvar = 0;
    const int limit = 1000;

    void ff()
    {
    }
}
int ivar = 0;
// position 1
// using Exercise::ivar;
// using Exercise::dvar;
// using Exercise::limit;

// using namespace Exercise;

void ff() {}

void manip()
{
    // position 2
    // using Exercise::ivar;
    // using Exercise::dvar;
    // using Exercise::limit;

    using namespace Exercise;
    using Exercise::ff;
    ff();
    // using namespace Exercise;

    double dvar = 3.1416;
    int iobj = limit + 1;
    ++ivar;
    ++::ivar;
}

namespace n1
{
    // int ivar = 12;
    namespace n2
    {
        int ivar = 43;
    }

    void manip()
    {
        using namespace n2;
        ++ivar;
    }
}


namespace T
{
    using namespace Exercise;
    // using Exercise::ivar;
    int vv = ivar;
}