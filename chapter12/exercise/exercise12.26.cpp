#include <string>
#include <iostream>
#include <memory>
#include <new>

#define N 12

using namespace std;

int main(int argc, char const *argv[])
{
    // Allocate uninitialized memory
    allocator<string> alloc_s;
    auto const ps = alloc_s.allocate(N);
    auto qs = ps;
    string line;
    // Read strings from `stdin` line by line
    while (getline(cin, line) && qs < ps + N) {
        uninitialized_fill_n(qs++, 1, line);
    }

    // Print the ps
    while (ps != qs) {
        cout << *--qs << endl;
        alloc_s.destroy(qs);
    }
    
    // Deallocate the memory
    alloc_s.deallocate(ps, N);
    return 0;
}
