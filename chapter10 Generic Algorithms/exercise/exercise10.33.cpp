#include <fstream>
#include <iterator>
#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    ifstream is("ints");
    ofstream os1("odds"), os2("evens");
    if (is && os1 && os2) {
        istream_iterator<int> is_iter(is), eof;
        ostream_iterator<int> os_iter1(os1, " "), os_iter2(os2, "\n");
        for_each(is_iter, eof, [os_iter1, os_iter2](int i) mutable 
                 { (i % 2 == 0 ? os_iter2 : os_iter1) = i; });
    }

    return 0;
}
