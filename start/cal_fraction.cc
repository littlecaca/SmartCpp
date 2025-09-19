#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

string divide(int a, int b) {
    string ans = a * b < 0 ? "-" : "";
    a = abs(a);
    b = abs(b);
    ans += to_string(a / b);
    a = a % b;
    if (a == 0) {
        return ans;
    }
    ans += ".";
    unordered_map<int, int> memo;
    while (a > 0) {
        auto it = memo.find(a);
        if (it != memo.end()) {
            ans.insert(it->second, 1, '(');
            ans += ")";
            return ans;
        }
        auto old = a;
        ans += '0' + a * 10 / b;
        a = a * 10 % b;
        memo.emplace(old, ans.size() - 1);
    }
    return ans;
}

int main() {
    cout << divide(1, 2) << endl;
    cout << divide(-1, 3) << endl;
    cout << divide(5, 43) << endl;
    cout << divide(6, 7) << endl;
    cout << divide(3, -4) << endl;
    return 0;
}
