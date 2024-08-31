#include <atomic>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    atomic<int> value = 31;
    cout << value << endl;
    return 0;
}
