#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(int argc, char const *argv[])
{
    string input;
    while (cin >> input) {
        if (input == "exit")
            goto end;
    }
    // label identifiers are independent of names used for variables and other identifiers
    // function scope: the goto and label must be in the same function
    // as with a switch statement, the goto cannot jump from a point where an initialized variable is out
    // of scope to a point where that variable is in scope

    // jumping back to a point before a variable is defined destorys the variable and constructs it again
    end: cout << "over" << endl;
    cout << "🈚, 🐮🐭🐘" << endl;

    goto next;
    
    int i;
    // int i = 1; // error
    next: i = 9;

    return 0;
}


