#include <vector>
#include <iostream>
#include <new>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::nothrow;

vector<int> *get_vc() {
    return new (nothrow) vector<int>;
}

void read_ints(vector<int> *pvc) {
    int temp;
    while (cin >> temp) {
        pvc->push_back(temp);
    }
}

void print_ints(const vector<int> *pvc) {
    for (int i : *pvc) {
        cout << i << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    auto pvc = get_vc();
    if (pvc) {
        read_ints(pvc);
        print_ints(pvc);
        delete pvc;
    } else cout << "cannot allocate new dynamic memeory" << endl;
   

    return 0;
}
