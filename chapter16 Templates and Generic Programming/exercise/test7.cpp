#include <string>
#include "T1.h"

extern template class T1<std::string>;

int main(int argc, char const *argv[])
{
    /* code */
    T1<std::string> t;
    t.print("sda");
    return 0;
}
