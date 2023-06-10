#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    vector<int> vi{1, 2, 3};
    cout << "capacity: " << vi.capacity() << " "
         << "size: " << vi.size() << endl;
    int round = 5;
    while (round--) {
        for (auto i = vi.size(); i < vi.capacity(); ++i)
            vi.push_back(0);

        vi.push_back(0);
        cout << "capacity: " << vi.capacity() << " "
             << "size: " << vi.size() << endl;
    }
    
    return 0;
}
