#include <iostream>
#include <iterator>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;

void print(const int i, int (&j)[2]) {
    cout << i << " ";
    for (auto elem : j) {
        cout << elem << " ";
    }
    cout << endl;
}

void print(const int i, int j[], int size) {
    cout << i << " ";
    for (int i = 0; i < size; ++i) {
        cout << j[i] << " ";
    }
    cout << endl;
}

void print(const int i, const int *beg, const int *const end) {
    cout << i << " ";
    while (beg != end) {
        cout << *beg++ << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[]) {
    int i = 0, j[2] = {0, 1};

    print(i, j);
    print(i, j, 2);
    print(i, begin(j), end(j));
    return 0;
}
