#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;


long long sum(const vector<string> &numstrs) {
    long long total = 0;
    for (auto & s : numstrs) {
        total += std::stoll(s);
    }
    return total;
}

double sum_float(const vector<string> &numstrs) {
    double total = 0;
    for (auto & s : numstrs) {
        total += std::stod(s);
    }
    return total;
}

int main(int argc, char const *argv[])
{
    cout << sum(vector<string>{"1", "2", "3"}) << endl;
    cout << sum_float(vector<string>{"2.33", "23.44"}) << endl;
    return 0;
}
