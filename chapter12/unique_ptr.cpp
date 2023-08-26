#include <iostream>
#include <memory>
#include <string>
#include <vector>

using std::cout;
using std::unique_ptr;
using std::shared_ptr;
using std::endl;
using std::cin;
using std::string;
using std::vector;

/*
 * Operations Specific to unique_ptrs (the common operations is listed before)
 * 
 * unique_ptr<T> u1         u1 will use delete to free its pointer.
 * unique_ptr<T, D> u2      u2 will use a callable object of type D to free its pointer.
 * unique_ptr<T, D> u(d)    d is an object of type D in place of delete.
 * 
 * u = nullptr              Deletes the object to which u points; makes u null.
 * u.release()              Reinquishes control of the pointer u had held; returns the
 *                          pointer u had held and makes u null.
 * 
 * u.reset()                Deletes the object to which u points; Makes u null
 * u.reset(q)               Makes u point to that object.
 * u.reset(nullptr)         Equivalent to u.reset().
 * 
 * 
 * There is no library function comparable to
 * make_shared that returns a unique_ptr. When we define a unique_ptr,
 * we bind it to a pointer returned by new.
 * 
 * Because a unique_ptr owns the object to which it points, unique_ptr
 * does not support ordinary copy or assignment.
 * 
 * A dangerous scenario leading to memory leak is:
 * p.release();
 * p won't free the memory and we've lost the pointer.
 * 
 * 
 * 
 * Passing and Returning unique_ptrs
 * 
 * We can copy or assign a unique_ptr that is about to be destroyed.
 * The most common example is when we return a unique_ptr from a function.
 * 
 * 
 * 
 * Passing a Deleter to unique_ptr
 * 
 * For some reasons, the way unique_ptr manages its deleter is differs from
 * the way shared_ptr does.
 * 
 */

void free_int(int *i) {

}

int main(int argc, char const *argv[])
{
    // When reset takes void or nullptr, it makes itself null
    unique_ptr<int> p1(new int(42));
    p1.reset(nullptr);
    if (p1 == nullptr)
        cout << "p1 is a nullptr" << endl;
    else
        cout << "p1 is not!" << endl;

    // Transfers ownership from p2 to p1
    unique_ptr<int> p2(new int(21));
    p1.reset(p2.release());
    cout << *p1 << endl;

    // Create an unique_ptr indicating a deleter
    unique_ptr<int, void (*)(int *)> p(new int(42), free_int);

    // See what errors will happen when we copy or assign a unique_ptr
    unique_ptr<int, decltype(free_int) *> p2(new int(41), free_int);
    // p = p2;     // no operator "=" matches these operands
    
    return 0;
}
