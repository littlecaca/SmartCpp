#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

using std::cout;
using std::endl;
using std::unordered_map;
using std::unordered_set;
using std::string;
using std::hash;

/*
 * Use an unordered container if the key type is inherently unordered
 * of if performance testing reveals problems that hashing might solve.
 * 
 * 
 * Manageing the Buckets
 * 
 * When a bucket holds several elements, those elements are searched 
 * sequentially to find the one we want.
 * 
 * Bucket Interface
 * 
 * c.bucket_count()
 * c.max_bucket_count()
 * c.bucket_size(n)         Number of elements in the nth bucket
 * c.bucket(k)              Bucket in which elements with key k wounld be found
 * 
 * Bucket Iteration
 * 
 * local_iterator           Iterator type that can access elements in a bucket
 * const_local_itterator    const version
 * c.begin(n), c.end(n)
 * c.cbegin(), c.cend()
 * 
 * Hash Policy
 * 
 * c.load_factor()          Average number of elements per bucket. Returns float.
 * c.max_load_factor()      Average bucket size that c tries to maintain. c adds buckets
 *                          to keep load_factor <=  max_load_factor. Returns float.
 * c.rehash(n)              Reorganize storage so that bucket_count >= n and bucket_count
 *                          > size/max_load_factor.
 * c.reserve(n)             Reorgainize so that c can hold n elements without a rehash.
 * 
 * 
 * Requirements on Key Type for Unordered Containers
 * 
 * By default, the unordered containers use an onject of type hash<key_type> to generate
 * the hash code for each element. We can directly define unordered containers whose key is
 * one of the built-in types(including pointer types), or a string, or a smart pointer.
 * 
 * Unlike the containers, we cannot use the hash template directly.
 * We cna use a stragey similar to the one we used to overide the default comparision operation
 * on keys for the ordered containers.
 * 
 */


// our own hash function
size_t hasher(const string &s) {
    return hash<string>() (s);
}

// equal operator
bool eqOp(const string &lhs, const string &rhs) {
    return lhs == rhs;
}

int main(int argc, char const *argv[])
{
    unordered_map<int, int> um(90);
    cout << um.bucket_count() << endl;
    cout << um.max_bucket_count() << endl;
    cout << um.bucket_size(0) << endl;

    um[3] = 3;

    cout << um.bucket_count() << endl;
    cout << um.max_bucket_count() << endl;
    cout << um.bucket_size(0) << endl;

    cout << "max_load_factor : " << um.max_load_factor() << endl;

    string words = "you";

    // select our own hash function and comparision function for unordered associative containers
    using SD_multiset = unordered_set<string, decltype(hasher) *, decltype(eqOp) *>;
    
    // only select our own hash function
    using SH_multiset = unordered_set<string, decltype(hasher) *>;

    return 0;
}
