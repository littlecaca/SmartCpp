#include <iostream>
#include <algorithm>

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

Digit* substrat(Digit* x, Digit* y) {
    // 假设x > y
    int borrow = 0;
    string res;
    auto to_num = [](char ch) -> int {
        return ch >= 'a' ? 10 + ch - 'a' : ch - '0';
    };
    auto to_ch = [](int num) -> char {
        return num >= 10 ? 'a' + num - 10 : '0' + num;
    };
    while (x) {
        int cur = to_num(x->n) - borrow;
        x = x->next;
        if (y) {
            cur -= to_num(y->n);
            y = y->next;
        }
        if (cur < 0) {
            cur += 16;
            borrow = 1;
        } else {
            borrow = 0;
        }

        res.push_back(to_ch(cur));
    }
    reverse(res.begin(), res.end());
    Digit presudo{-1, nullptr};
    Digit* head = &presudo;
    for (int i = res.find_first_not_of('0'); i != string::npos && i < res.size(); ++i) {
        head->next = new Digit{res[i], nullptr};
        head = head->next;
    }
    return presudo.next;
}

int main() {
    cout << "start test!" << endl;
    string xs = "ffffffffffffee";
    string ys = "fffffffff11234";
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
    // auto res_list = sum(xlist, ylist);
    auto res_list = substrat(xlist, ylist);
    cout << "the result is:" << endl;
    while (res_list) {
        cout << res_list->n << " ";
        res_list = res_list->next;
    }
    return 0;
}
