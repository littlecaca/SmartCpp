#include <iostream>
#include <algorithm>
#include <list>

using std::cout;
using std::endl;
using std::for_each;
using std::list;

int main(int argc, char const *argv[])
{
    // plain function pointer can't hold the lambdas that have capture list elements
    int (*f)(int, int) = [] (int i1, int i2) -> int { 
        cout << "ok" << endl;
        return i1 + i2; 
    };
    list<int> li{1, 2, 3, 4};
    int num = 2;
    for_each(li.begin(), li.end(), [num] (int i)
             { cout << num + i << " "; });
    cout << endl;
    
    cout << f(2, 5) << endl;

    return 0;
}
