#include <string>

using std::string;

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

string (&getStrings())[10] {
    static string strs[10] = {};
    return strs;
}

using tenStr = string[10];
tenStr &getStrings2() {
    static string strs[10] = {};
    return strs;
}

auto getString3() -> string (&)[10] {
    static string strs[10] = {};
    return strs;
}

string strs[10];
decltype(strs) &getString4() {
    static string strs[10] = {};
    return strs;
}
