#include <iostream>

using namespace std;

struct Digit {
    char n;
    Digit* next;
};

Digit* sum(Digit* x, Digit* y) {
    Digit presudo{-1, nullptr};
    auto to_num = [](char ch) -> int {
        return ch >= 'a' ? 10 + ch - 'a' : ch - '0';
    };
    auto to_ch = [](int num) -> char {
        return num >= 10 ? 'a' + num - 10 : '0' + num;
    };
    int cur = 0;
    Digit* head = &presudo;
    while (x || y || cur > 0) {
        if (x) {
            cur += to_num(x->n);
            x = x->next;
        }
        if (y) {
            cur += to_num(y->n);
            y = y->next;
        }
        Digit* tar = new Digit{to_ch(cur % 16), nullptr};
        head->next = tar;
        head = tar;
        cur /= 16;
    }
    return presudo.next;
}

int main() {
    cout << "start test!" << endl;
    string xs = "ffffffff";
    string ys = "1";
    auto get_list = [](const string& str) -> Digit* {
        Digit presudo{-1, nullptr};
        Digit* head = &presudo;
        for (auto it = str.rbegin(); it != str.rend(); ++it) {
            head->next = new Digit{*it, nullptr};
            head = head->next;
        }
        return presudo.next;
    };
    auto xlist = get_list(xs);
    auto ylist = get_list(ys);
    auto res_list = sum(xlist, ylist);
    cout << "the result is:" << endl;
    while (res_list) {
        cout << res_list->n << " ";
        res_list = res_list->next;
    }
    return 0;
}
