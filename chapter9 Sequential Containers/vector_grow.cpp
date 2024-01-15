/*
 * How a vector Grows
 * 
 * When they have to get new memory, vector and string implementations typically allocate capacity beyond what is immediately
 * needed. In fact, its performance is good enough that in practice a vector usually grows more efficiently than a list or a deque,
 * even though the vector has to move all of its elements each time it reallocates memory.
 * 
 * 
 * Members to Manage Capacity
 * 
 * shrink_to_fit valid only for vector, string, and deque.
 * capacity and reserve valid only for vector and string.
 * 
 * c.shrink_to_fit()    Request to reduce capacity() to equal size()
 * c.capacity()         Number of elements c can have before reallocation is necessary
 * c.reserve(n)         Allocate space for at least n elements.
 * 
 * A call to reserve changes the capacity of the vector only if the requested space exceeds the
 * current capacity. The implementation is free to ignore the request to shrink_to_fit. There is
 * no guarantee that a call to shrink_to_fit will return memory.
 * 
 * In fact, as long as no operation exceeds the vector's capacity, the vector must not reallocate its
 * elements. A vector may be reallocated only when the user performs an insert operation when the size equals 
 * capacity or by a call to resize or reserve with a value that exceeds the current capacity. How much 
 * memory is allocated beyong the specified amount is up to the implementation.
 * 
 * Technically speaking, the execution time of creating an n-element vector by calling push_back n times on an
 * initially empty vector must never be more than a constant multiple of n (O(n)). (why do I think it is O(log(n) * n)
*/