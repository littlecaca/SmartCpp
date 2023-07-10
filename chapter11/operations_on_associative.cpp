#include <map>
#include <utility>
#include <iostream>
#include <vector>
#include <set>

using namespace std;


/*
 * Associative Container Additional Type Aliases
 *
 * key_type
 * mapped_type  map types only
 * value_type   For sets, same as the key_type
 *              For maps, pair<const key_type, mapped_type>
 * 
 * 
 * Associative Container Iterators
 * 
 * Iterators for sets Are const.
 * 
 * 
 * Associative Containers and Algorithms
 * 
 * Associative containers can be used with the algorithms that read elements.
 * However, many of these algorithms search the sequence. It is much faster to
 * use the member defined by the container than to call the generic version.
 * 
 * 
 * Adding Elements
 * 
 * For map and set (and the corresponding unordered types), inserting an element
 * that is already present has no effect.
 * 
 * c.insert(v)          v is a value_type object
 * c.emplace(args)      args are used to construct an element.
 *                      Returns a pair containing an iterator referring to the element
 *                      with the given key and a bool indicating whether the element was inserted.
 *                      For multimap and multiset, inserts (or constructs) the given element
 *                      and returns an iterator to the new element.
 * 
 * c.insert(b, e)       Returns void.
 * c.insert(i1)         i1 is a braced list of such values. Returns void.
 * 
 * c.insert(p, v)       Uses iterator p as a hint for where to begin the search for where the new element
 *                      should be stored. Returns an iterator to the element with the given key.
 * c.emplace(p, args)
 * 
 * 
 * Unwinding the Syntax
 * 
 * 
 * Erasing Elements
 * 
 * c.erase(k)   Removes every element with key k from c. Returns size_t
 *              indicating the number of elements removed.
 * 
 * c.erase(p)   Removes the element denoted by the iterator p from c. p must refer 
 *              to an actual element in c; Returns an iterator to the element after p
 *              or c.end().
 * 
 * c.erase(b, e)    Removes the elements in the range denoted by the iterators. Returns e.
 * 
 * 
 * Subscripting a map   
 * 
 * Not for multimap, unordered_multimap and set.
 * 
 * c[k]     If k is not in c, adds a new, value-initialized element with key k.
 * 
 * c.at(k)  Throws an out_of_range exception if k is not in c.
 * 
 * 
 */

int main(int argc, char const *argv[])
{
    vector<int> vi;
    vi.insert(vi.end(), {1, 2, 3});

    cout << "Hello World  JLU" << endl;


    map<int, int> m;
    auto re = m.insert({1, 3});
    cout << re.first->first << " : " << re.first->second 
         << " " << re.second << endl;

    // erasing elements
    // auto ret1 = m.erase(1);
    // auto ret2 = m.erase(m.begin());
    // auto ret3 = m.erase(m.begin(), m.end());

    auto ret4 = m.at(1);
    cout << ret4 << endl;
    cout << "ok!" << endl;
    
    return 0;
}
