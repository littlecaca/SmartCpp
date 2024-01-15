#include <iostream>

using namespace std;

/*
 * The list define their own versions of sort, merge, remove, reverse,
 * and unique.
 * 
 * The generic version of sort cannot be used with list and forward_list.
 * 
 * The generic versions of the other algorithms that the list types define 
 * can be used with lists, but at a cost in performance.
 * 
 * 
 * Algorithms That are Members of list and forward_list
 * 
 * lst.merge(lst2)
 * lst.merge(lst2, comp)
 * 
 * lst.remove(val)
 * lst.remove_if(pred)
 * lst.reverse()
 * lst.sort()
 * lst.sort(comp)
 * lst.unique()
 * lst.unique(pred)
 * 
 * Best Pratices: The list member versions should be used in preference to the generic
 * algorithms for lists and forward_lists.
 * 
 * 
 * The splice Members
 * 
 * lst.splice(args) or flst.splice_after(args)
 * 
 * (p, lst2)
 * (p, lst2, p2)    lst2 can be the same list as lst or flst
 * (p, lst2, b, e)  lst2 can be the same list as lst or flst
 * 
 * 
 * The List-Specific Operations Do Change the Containers
 * 
 * For example, the list version of remove does remove the indicated elements.
 * Similarly, merge and splice are destructive on their arguments.
 * 
 * 
 */

int main(int argc, char const *argv[])
{
    /* code */
    
    return 0;
}
