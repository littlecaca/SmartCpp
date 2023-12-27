#include <iostream>
#include <memory>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    shared_ptr<int> sp(new int, [](int *p) { cout << "yes" << endl; delete p; });
    auto sp2 = sp;
    auto sp3(sp);
    cout << sp3.use_count() << endl;
    return 0;
}
