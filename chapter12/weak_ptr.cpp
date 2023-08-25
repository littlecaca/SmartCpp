#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <new>

using std::bad_alloc;
using std::nothrow;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::weak_ptr;
using std::shared_ptr;


/*
 * A weak_ptr is a smart pointer that does not control the lifetime
 * of the object to which it points. When we create a weak_ptr, we
 * initialize it from a shared_ptr.
 * 
 * Operations of weak_ptr
 * 
 * weak_ptr<T> w
 * weak_ptr<T> w(sp)
 * 
 * w = p
 * 
 * w.reset()
 * w.use_count()
 * w.expired()      Returns true if w.use_count() is zero, false otherwise.
 * w.lock()         If expired is true, returns a null shared_ptr; otherwise
 *              	returns a shared_ptr to the object to which w points.
 * 
 * 
 */


int main(int argc, char const *argv[])
{
	auto sp = shared_ptr<int>(new int(42));
	weak_ptr<int> wp(sp);

	// Access the objects by weak_ptr
	if (auto np = wp.lock()) {
		// inside the if, np shares its object with sp
	}
	
	
	return 0;
}
