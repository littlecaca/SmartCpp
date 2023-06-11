#include <stack>
#include <string>
#include <iostream>

using std::stack;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[])
{
    string expression = "(1 + 2) - 3 + 5 - (4 - 10)";
    char val1, op, val2, res = '?';
    stack<char> stk;
    for (auto c : expression) {
        if (!isspace(c)) {
            if (c == '(') stk.push(c);
            else if (c == ')' || stk.top() != '(') {
                val1 = stk.top();
                op = stk.top();
                val2 = stk.top();
                stk.push(res);
            } else {
                stk.push(c);
            }
        }
    }
    return 0;
}
