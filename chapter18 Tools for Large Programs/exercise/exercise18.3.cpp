#include <fstream>
#include <memory>
#include <iostream>
#include <vector>

using namespace std;

void exercise(int *b, int *e) {
    vector<int> v(b, e);
    // from C++ 17, the shared_ptr supports operator[]
    shared_ptr<int> p(new int[v.size()], [](int *ptr) {
        delete[] ptr;
    });
    ifstream in("ints");
    // exception occurs here
    
}

int main(int argc, char const *argv[])
{
    cout << "yes" << endl;
    return 0;
}
