#include <map>
#include <stdexcept>
#include <sstream>
#include <utility>
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <unordered_map>
#include <fstream>

using namespace std;
using std::runtime_error;


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
 * Because the subscript operator might insert an element, we may use subscript only
 * on a map that is not const.
 * 
 * Note
 * Unlike vector or string, the type returned by the map subscript operator differs
 * from the type obtained by dereferenceing a map iterator.
 * 
 * 
 * Accessing Elements
 * 
 * lower_bound and upper_bound not valid for the unordered containers.
 * Subscript and at operations only for map and unordered_map that are not const.
 * 
 * c.find(k)    Returns the off-the-end iterator if k is not in the container.
 * 
 * c.count(k)   
 * 
 * c.lower_bound(k)     Returns an iterator to the first element with key not less 
 *                      than k.
 * c.upper_bound(k)     Returns an iterator to the first element with key greater
 *                      than k.
 * c.equal_range(k)     Returns a pair of iterators denoting the elements with key k.
 *                      If k is not present, both members refer to the position where 
 *                      this key can be inserted.
 * 
 * Note
 * 
 * The itetrator returned from lower_bound may or may not refer to an element with the 
 * given key. If the key is not in the container, then lower_bound and upper_bound both
 * refer to the first point at which this key can be inserted while preserving the element
 * order within the container.
 * 
 *  
 * 
 */

constexpr int multiple(int n) {
    int y = n / 3;
    // cout << "yes";
    if (y % 2 == 0)
        return y;
    else
        return y * 2;
    // return n * 2;
}

int main(int argc, char const *argv[])
{
    vector<int> vi;
    vi.insert(vi.end(), {1, 2, 3});

    cout << "Hello World  JLU" << endl;


    map<int, int> m;
    map<string, size_t> m2;
    auto re = m.insert({1, 3});
    cout << re.first->first << " : " << re.first->second 
         << " " << re.second << endl;

    // erasing elements
    // auto ret1 = m.erase(1);
    // auto ret2 = m.erase(m.begin());
    // auto ret3 = m.erase(m.begin(), m.end());

    auto ret4 = m.at(1);
    auto ret5 = m2["you"];
    auto ret6 = m2.at("you");
    cout << ret4 << endl;
    cout << "ok!" << endl;
    
    multiset<int> ms = {1, 3, 3, 4, 4, 4, 5, 6};
    auto range_pair = ms.equal_range(2);
    if (range_pair.first == ms.end())
        cout << "both refer to off-the-end element" << endl;
    else 
        cout << *range_pair.first << " " << *range_pair.second << endl;

    auto ret7 = ms.find(3);
    constexpr int i = multiple(22);
    cout << i << endl;

    cout << string(30, '-') << endl;
    string transform(const string &, const string &);
    cout << transform("rules.txt", "raw.txt") << endl;
    return 0;
}


// a word transformation map
string transform(const string &rule_file, const string &transformed_file) {
    map<string, string> rules;
    ifstream rule_s(rule_file), raw_s(transformed_file);
    ostringstream transformed;

    // read the rules into a map
    string word, line;
    while (getline(rule_s, line)) {
        size_t edge = line.find_first_of(' ');
        if (edge >= line.size() - 1)
            throw runtime_error("no rule for " + line);
        rules[line.substr(0, edge)] = line.substr(edge + 1);
    }

    // transform
    istringstream buffer;
    while (getline(raw_s, line)) {
        
        buffer.str(line);
        while (buffer >> word) {
            decltype(rules.begin()) it;
            if ((it = rules.find(word)) != rules.end())
                transformed << it->second;
            else
                transformed << word;

            if (!buffer.eof())
                transformed << " ";
        }
        // reset the buffer
        buffer.clear();
        if (!raw_s.eof())
            transformed << "\n";
    }

    return transformed.str();
}