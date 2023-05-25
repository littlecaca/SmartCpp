#include <vector>
#include <iostream>
#define NODEBUG

using std::vector;
using std::cout;
using std::cin;
using std::endl;

void printContent(const vector<int> &vi, vector<int>::size_type index) {
    if (index != vi.size()) {
        #ifndef NODEBUG
        cout <<  "index:" << index << "->";
        #endif
        cout << vi[index] << " ";
        printContent(vi, index + 1);
    } 
    #ifndef NODEBUG
    else {
        cout << endl << __func__ << endl;
    }
    #endif
}   

int main(int argc, char const *argv[])
{
    vector<int> vi{1, 3, 4, 5, 7, 5, 6, 8, 7, 8, 8, 8};
    printContent(vi, 0);
    /* code */
    return 0;
}
