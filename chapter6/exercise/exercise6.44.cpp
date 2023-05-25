#include <string>

using std::string;

inline bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}


// error: call to non-constexpr function
// constexpr bool isShorter2(const string &s1, const string &s2) {
//     return s1.size() < s2.size();
// }

constexpr int cal(int i) {
    constexpr int y = 898 * 21;
    return 2 * y;
}

int main(int argc, char const *argv[])
{   
    constexpr int i = 5;
    constexpr int j = cal(i);
    /* code */
    return 0;
}

