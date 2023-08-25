#include <iostream>
#include <new>
#include <string>

using namespace std;

char *concatenate(const char *s1, const char *s2, size_t l1, size_t l2) {
    char *char_a = new char[l1 + l2 + 1], *temp = char_a;

    while (*s1 != '\0')
        *(temp++) = *(s1++);
    while (*s2 != '\0')
        *(temp++) = *(s2++);

    return char_a;
}

int main(int argc, char const *argv[]) {
    string s1 = "You are brilient", s2 = " but not enough";
    char *result = concatenate(s1.c_str(), s2.c_str(), s1.length(), s2.length());

    string s3 = s1 + s2;

    cout << result << endl;
    cout << s3 << endl;
    return 0;
}
