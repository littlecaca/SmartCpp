#include <bitset>
#include <iostream>

using namespace std;

// mark one quiz true/false
void mark(bitset<100> &res, size_t quiz, bool ans)
{
    if (ans)
        res.set(quiz - 1);
    else
        res.reset(quiz - 1);
}


int main(int argc, char const *argv[])
{
    bitset<100> res;
    unsigned long long record = 0;
    int pos = 10;
    // mark the pos quiz false
    record &= ~(1 << 10);
    // mark the pos quiz true
    record |= 1 << 10;
    // check the state of pos
    bool status = record & (1 << 10);
    
    if (status) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0; 
}
