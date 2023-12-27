#include <vector>
#include <iostream>
#include <memory>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::make_shared;
using std::shared_ptr;

shared_ptr<vector<int>> get_vc() {
    return make_shared<vector<int>>();
}

void read_ints(shared_ptr<vector<int>> pvc) {
    int temp;
    while (cin >> temp) {
        pvc->push_back(temp);
    }
}

void print_ints(shared_ptr<const vector<int>> pvc) {
    for (int i : *pvc) {
        cout << i << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    auto pvc = get_vc();
    read_ints(pvc);
    print_ints(pvc);
    
    return 0;
}
