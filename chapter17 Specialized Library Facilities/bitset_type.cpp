#include <bitset>
#include <iostream>

using namespace std;

#define Print(vec) \
    cout << vec << endl;

#define Test(bitvec, method) \
    if (bitvec.method()) \
        cout << "yes"; \
    else cout << "no"; \
    cout << " " #bitvec "." #method " "; \
    Print(bitvec);

#define Output(bitvec, method) \
    cout << bitvec.method() << " " #bitvec "." #method " "; \
    Print(bitvec);

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
    Print(bitVec1);
    Print(bitVec2);


    // bitset operations
    bitset<10> b(~0);
    bitset<10> b2;
    bitset<10> b3(11);
    const bitset<10> cb4(11);

    Test(b3, any)
    Test(b, all)
    Test(b2, none)
    Output(b3, count)
    Output(b3, size)
    
    /*
     * Note
     * These operations throw an overflow_error exception (§ 5.6, p. 193) if the
     * value in the bitset does not fit in the specified type.
     */
    Output(b3, to_ulong)
    Output(b, to_ulong)

    /*
     *     The subscript operator is overloaded on const. The const version returns a bool
     * value true if the bit at the given index is on, false otherwise. The nonconst
     * version returns a special type defined by bitset that lets us manipulate the bit value
     * at the given index position
     */
    auto res1 = cb4[0];
    auto res2 = b3[0];
    
    return 0;
}
