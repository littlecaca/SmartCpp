#include <bitset>
#include <iostream>

using namespace std;

#define print(vec) \
    for (int i = vec.size() - 1; i >= 0; --i) \
        cout << vec[i]; \
    cout << endl;

#define test(bitvec, method) \
    if (bitvec.method()) \
        cout << "yes"; \
    else cout << "no"; \
    cout << " " #bitvec "." #method " "; \
    print(bitvec);

#define output(bitvec, method) \
    cout << bitvec.method() << " " #bitvec "." #method " "; \
    print(bitvec);

/*
 * The standard library defines the bitset class to make it easier to use
 * bit operations and possible to deal with collections of bits that are larger than the
 * longest integral type. The bitset class is defined in the bitset header.
 * 
 * bitset<n> b;     constexpr
 * bitset<n> b(u);  constexpr
 * bitset<n> n(s, pos, m, zero, one); explicit  s can only contains the characters `zero` and `one`,
 *      otherwise throws invalid_argument. zero defaults to '0', one defaults to '1'.
 * bitset<n> n(cp, pos, m, zero, one);  explicit
 * 
 * 
 * Note
 * The indexing conventions of strings and bitsets are inversely related:
 * The character in the string with the highest subscript (the rightmost
 * character) is used to initialize the low-order bit in the bitset (the bit with
 * subscript 0). When you initialize a bitset from a string, it is essential to
 * remember this difference.
 * 
 */

// Literal class
class BitSet
{
public:
    constexpr BitSet(int _num) : num(_num) {}
    constexpr int get() const { return num; }
private:
    int num;
};


int main(int argc, char const *argv[])
{
    constexpr BitSet bit{32};
    int arr[bit.get()] = {12};
    cout << sizeof(arr) / sizeof(int) << endl;
    cout << arr[0] << endl;

    constexpr int i = bit.get();

    bitset<32> bitVec(1U);
    if (bitVec[0])
    {
        cout << "1" << endl;
    }

    bitset<20> bitVec1(0xbeef);
    bitset<13> bitVec2(0xbeef);
    print(bitVec1);
    print(bitVec2);


    // bitset operations
    bitset<10> b(~0);
    bitset<10> b2;
    bitset<10> b3(11);

    test(b3, any)
    test(b, all)
    test(b2, none)
    output(b3, count)
    return 0;
}
