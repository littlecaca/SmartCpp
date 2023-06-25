#include <algorithm>
#include <set>
#include <sstream>
#include <iostream>
#include <map>
#include "../chapter7/access_specifiers.h"


using namespace std;

/*
 * Associative Container Types
 *
 * Elements Ordered by Key
 * 
 * map          The keys in a map or a set must be unique.
 * set 
 * multimap
 * multiset
 * 
 * Unordered Collections (organized by a hash function)
 * 
 * unordered_map        
 * unordered_set        
 * unordered_multimap
 * unordered_multiset
 * 
 * The map and multimap types are defined in the map header; 
 * The set and multiset types are in the set header;
 * And the unordered containers are in the unordered_map and 
 * unordered_set headers.
 * 
 * 
 * Using an Associative Container
 * 
 * The map type is often refered to as an associative array.
 * 
 * When we fetch an element from a map, we get an object of type pair.
 * 
 * 
 * Requirements on Key Type
 * 
 * The associative containers place constraints on the type that is used 
 * as a key. For the oredered containers--map, multimap, set, and multiset--
 * the key type must define a way to compare the elements. By default, the
 * library uses the < operator for the key type to compare the keys.
 * 
 * 
 * Key Types for Ordered Containers
 * 
 * We can supply our own operation to use in place of the < operator on keys.
 * The specified operation must define a strick weak ordering over the key type.
 * The strick weak ordering is like the < operator.
 * 
 * 
 * Using a Comparision Function for the Key Type
 * 
 * 
 * 
 * 
 */

int main(int argc, char const *argv[])
{
    // using a map

    map<string, size_t> word_count;
    istringstream is("this Is, is an is, good thing good");
    string word;

    
    // using a set

    set<string> exclude = {"the", "is", "a"};

    while (is >> word) {
        if (!isalnum(word.back()))
            word.pop_back();
        transform(word.begin(), word.end(), word.begin(), [](char c) { return tolower(c); });
        if (exclude.find(word) == exclude.end())
            ++word_count[word];
    }
    
    for (const auto &w : word_count)
        cout << w.first <<  " occurs " << w.second
             << ((w.second > 1) ? " times" : " time") << endl;


    // list initialize a map
    map<string, string> dic = {
        {"you", "are"},
        {"really", "a"},
    };

    for (const auto &s : dic) {
        cout << s.first << " ";
    }
    cout << endl;

    // define a associative container using our own comparision type
    multiset<Sales_data, bool (*)(const Sales_data &, const Sales_data &)>
        bookstore(compareIsbn);
    
    // or we can use decltype, we must add * to indicate that we're using apointer to the given function type.
    multimap<Sales_data, size_t, decltype(compareIsbn) *>
        bookrank(compareIsbn);
    
    return 0;
}
