#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    const char * const volatile word = "hello";
    char *c1 = nullptr;
    auto w = word;
    const auto &w2 = word;
    auto *w3 = word;
    const auto *w4 = c1;

    cout << w << endl;
    cout << w2 << endl;
    cout << w3 << endl;
    return 0;
}
