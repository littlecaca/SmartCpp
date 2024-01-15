#include <iostream>
#include <initializer_list>
#include <string>

using std::string;
using std::initializer_list;
using std::cout;
using std::cin;
using std::endl;

void errorMsg(initializer_list<string> ls) {
    for (auto &es : ls) {
        cout << es << endl;
    }
}

int main(int argc, char const *argv[])
{
    /*
     * There two primary ways to write a function that takes a varying
     * number of arguments. The `initializer_list` and `variadic template`.
     * 
     * And also, the special ellipsis parameter can also provide this function. But
     * this facility should only used to interface to C code.
     * 
     * 
     * initializer_list
     * 
     * Unlike vector, the elements in an initializer_list are always const values.
     */
    
    errorMsg({"you are a genius!", "Am I right?", "please answer me, please..."});
    return 0;
}
