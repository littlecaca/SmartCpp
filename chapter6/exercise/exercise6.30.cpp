#include <string>

using std::string;

int main() {
    return 0;
}

bool str_subrange(const string &st1, const string &st2) {
    if (st1.size() == st2.size())
        return st1 == st2;
    
    auto size = (st1.size() < st2.size()) ? st1.size() : st2.size();

    for (decltype(size) i = 0; i != size; ++i) {
        if (st1[i] != st2[i])
            // the compiler can detect this erorr: return-statement with no value, in function returning 'bool'
            // return;
            return 0; // ok
    }
}