#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <utility>

using std::allocator;
using std::cin;
using std::cout;
using std::endl;
using std::for_each;
using std::initializer_list;
using std::make_move_iterator;
using std::pair;
using std::string;
using std::uninitialized_copy;

/*
 * Note
 * The library containers, string, and shared_ptr classes support move as
 * well as copy. The IO and unique_ptr classes can be moved but not copied.
 *
 *
 * Rvalue References
 *
 * We can bind an rvalue reference to expressions that require a conversion,
 * to literals, or to expressions that return a rvalue, but we cannot directly
 * bind an rvalue reference to an lvalue.
 *
 *
 * Lvalues Persist; Rvalues Are Ephemeral
 *
 * Note
 * Rvalue references refer to objects that are about to be destroyed. Hence,
 * we can "steal" state from an obejct bound to an rvalue reference.
 *
 *
 * The library move function
 *
 * It is essential to realize that the call to move promises that
 * we do not intend to use that lvalue again except to assign to it or
 * to destroy it. After a call to move, we cannot make any assumptions
 * about the value of the moved_from obejct.
 *
 *
 * Warning
 * Code that uses move should use std::move, not move. Doing so avoids
 * potential name collisions.
 *
 *
 *
 * Move Constructor and Move Assignment
 *
 * Like the copy constructor, the move constructor has an initial parameter
 * that is a reference to the class type. As in the copy constructor, any
 * additional parameters must all have default arguments.
 *
 *
 *
 * Move Operations, Library Containers, and Exceptions
 *
 * Unless the library knows that our move constructor won't throw, it will
 * do extra work to cater to the possiblity that moving an object of our
 * class type might throw.
 *
 * Note
 * Move constructors and move assignment operators that cannot throw
 * exceptions should be marked as noexcept.
 *
 * The library containers provide guarantees as to what they do if an
 * exception happens. As one example, vector guarantees that if an
 * exception happens when we call push_back, the vector itself will be
 * left unchanged.
 *
 * To avoid the potential problem, vector must use a copy constructor
 * instead of a move constructor during reallocation unless it knows
 * that the element type's move constructor cannot throw an exception.
 *
 *
 *
 * Move-Assignment Operator
 *
 * Like a copy-assignment operator, a move-assignment operator
 * must guard against self-assignment.
 *
 * A Moved-from Object Must Be Destructible
 *
 * Warning
 * After a move operation, the "moved-from" object must remain
 * a valid, destructible object but users may make no assumptions
 * about its value.
 *
 *
 *
 * The Synthesized Move Operations
 *
 * The compiler will synthesize a move constructor or a move-assignment
 * oeprator only if the class doesn't define any of its own copy-control
 * members and if every nonstatic data member of the class can be moved
 * constructed and move assigned, respectively.
 *
 * Unlike the copy operations, a move operation is never implicitly defined
 * as a deleted function. However, if we explicitly ask the compiler
 * to generate a move operation by using = default, and the compiler
 * is unable to move all the members, then the move operation will be
 * defined as deleted. (p667 for details)
 *
 *
 * Note
 * Classes that define a move constructor or move-assignment operator
 * must also define their own copy opertions. Otherwise, those members
 * are deleted by default.
 *
 *
 *
 * Rvalues Are Moved, Lvalues Are Copied...
 *
 * ...But Rvalues Are Copied If There Is No Move Constructor
 *
 * We can convert a Foo&& to const Foo&.
 *
 *
 *
 * Copy-and-Swap Assigment Operators and Move
 *
 * HasPtr &operator=(HasPtr rhs)
 *      { swap(*this, rhs); return *this; }
 *
 * This single assignment operator acts as both the copy-assignment
 * and move-assignment operator.
 *
 *
 *
 * Advice: Updating the Rule of Three
 *
 * All five copy-control members should be thought of as a unit:
 * Ordinarily, if a class defines any of these operations, it
 * usually should define them all.
 *
 *
 * Move Operations for the Message Class (as a example in example.cpp)
 *
 *
 * Move Iterators
 *
 * The new library defines a move iterator adaptor. Unlike other iterators,
 * the dereference operator of a move iterator yields a rvalue reference.
 *
 * make_move_iterator(<original iterator>)
 *
 *
 * Advice: Don't Be Too Quick to Move
 *
 * Judiciously used inside class code, move can offer significant performance
 * benefits. Casually used in ordinary user code (as opposed to class
 * implementation code), moving an object is more likely to lead to mysterious
 * and hard-to-find bugs than to any improvement in the performance of the
 * application.
 *
 * Best Practices
 *
 * Outside of class implementation code such as move constructors or
 * move-assignment operators, use std::move only when you are certain
 * that you need to do a move and that the move is guaranteed to be safe.
 *
 *
 * Rvalue References and Member functions
 *
 * Note
 * Overloaded functions that distinguish between moving and copying a parameter
 * typically have one version that takes a const T& and one that takes a T&&.
 *
 * Note
 * If a member function has a reference qualifier, all the versions of that
 * member with the same parameter list must have reference qualifiers.
 */

struct X {
	int i;			 // built-in types can be moved
	std::string mem; // string defines its own move operations
};

struct hasX {
	X mem; // X has synthesized move operations
};

X x, x2 = std::move(x);
hasX hx, hx2 = std::move(hx); // uses the synthesized move constructor

class StrVec {
	friend bool operator==(const StrVec &, const StrVec &);
	friend bool operator<(const StrVec &, const StrVec &);

	pair<string *, string *> alloc_n_copy(const string *b, const string *e);
	pair<string *, string *> alloc_n(size_t);
	void free();
	void chk_n_alloc();
	void reallocate();
	void reallocate(size_t);

	allocator<string> alloc;
	// The three pointers marks the space
	string *elements;
	string *first_free;
	string *cap;

  public:
	StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const initializer_list<string> &);
	StrVec(const StrVec &);
	StrVec &operator=(const StrVec &);
	~StrVec() { free(); }
	// Move constructor
	StrVec(StrVec &&s) noexcept;
	// Move-Assignment Operator
	StrVec &operator=(StrVec &&rhs) noexcept;

	void push_back(const string &);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	string *begin() const { return elements; }
	string *end() const { return first_free; }
	void reserve(size_t);
	void resize(size_t);

	// Subscript operator
	std::string &operator[](size_t i) {
		return elements[i];
	}

	const std::string &operator[](size_t i) const {
		return elements[i];
	}

	// initializer_list assignment oeprators
	StrVec &operator=(initializer_list<string> il);
};

// Move Assignment Operator
StrVec &StrVec::operator=(StrVec &&rhs) noexcept {
	// Direct test for self-assignment
	if (this != &rhs) {
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		// Leave rhs in a destructible state
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	std::cout << "Move Assignment Operator BingGo!" << std::endl;
	return *this;
}

// Move Constructor
StrVec::StrVec(StrVec &&s) noexcept
	: elements(s.elements), first_free(s.first_free), cap(s.cap) {
	// Leave s in a state in which it is safe to run the destructor
	s.elements = s.first_free = s.cap = nullptr;
	std::cout << "Move Constructor BingGo!" << std::endl;
}

StrVec::StrVec(const initializer_list<string> &il) {
	auto ps = alloc_n_copy(il.begin(), il.end());
	elements = ps.first;
	first_free = cap = ps.second;
}

inline void StrVec::push_back(const string &s) {
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

pair<string *, string *> StrVec::alloc_n_copy(const string *b,
											  const string *e) {
	auto data = alloc.allocate(e - b);
	return {data, uninitialized_copy(b, e, data)};
}

pair<string *, string *> StrVec::alloc_n(size_t n) {
	auto data = alloc.allocate(n);
	return {data, data + n};
}

void StrVec::free() {
	if (elements) {
		std::for_each(elements, first_free,
					  [this](const string &sp) { alloc.destroy(&sp); });
		alloc.deallocate(elements, cap - elements);
	}
}

// Copy Constructor
StrVec::StrVec(const StrVec &sv) {
	auto ps = alloc_n_copy(sv.elements, sv.first_free);
	elements = ps.first;
	first_free = cap = ps.second;
	std::cout << "Copy Constructor BingGO!" << std::endl;
}

// Copy Assignment Operator
StrVec &StrVec::operator=(const StrVec &rhs) {
	auto ps = alloc_n_copy(rhs.elements, rhs.first_free);
	free();
	elements = ps.first;
	first_free = cap = ps.second;
	std::cout << "Copy Assignemnt Operator BingGo!" << std::endl;
	return *this;
}

inline void StrVec::reallocate() { reallocate(size() ? size() * 2 : 1); }

// Use the move iterators to substitute the for loop
void StrVec::reallocate(size_t new_cap) {
	// Allocate space for twice as many as elements as the current size
	auto newcapacity = new_cap;
	// Allocate new memory
	auto newdata = alloc.allocate(newcapacity);
	// Move the data
	auto last = uninitialized_copy(make_move_iterator(begin()),
								   make_move_iterator(end()), newdata);

	// for (size_t i = 0; i != size(); ++i)
	//     alloc.construct(dest++, std::move(*elem++));

	free();
	elements = newdata;
	first_free = last;
	cap = elements + newcapacity;
}

inline void StrVec::chk_n_alloc() {
	if (first_free == cap)
		reallocate();
}

inline void StrVec::reserve(size_t new_cap) {
	// If there are already elements
	if (elements)
		reallocate(new_cap);
	else {
		// Or if not
		auto ps = alloc_n(new_cap);
		elements = first_free = ps.first;
		cap = ps.second;
	}
}

void StrVec::resize(size_t new_size) {
	auto num = new_size - size();
	if (num > 0) {
		for (size_t i = 0; i < num; ++i) {
			push_back(std::string());
		}
	} else
		first_free += num;
}

// Equality Operator
bool operator==(const StrVec &lhs, const StrVec &rhs) {
	return lhs.size() == rhs.size() &&
		   std::mismatch(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())
				   .first == lhs.end();
}

// Inquality Operator
bool operator!=(const StrVec &lhs, const StrVec &rhs) { return !(lhs == rhs); }

// Less than Operator
bool operator<(const StrVec &lhs, const StrVec &rhs) {
	auto i1 = lhs.elements, i2 = rhs.elements;
	while (i1 != lhs.end() && i2 != rhs.end()) {
		if (*i1 != *i2)
			if (*i1 < *i2)
				return true;
			else
				return false;
		++i1;
		++i2;
	}

	return false;
}

// initializer Assignment Operator
StrVec &StrVec::operator=(initializer_list<string> il) {
	auto ps = alloc_n_copy(il.begin(), il.end());
	free();
	elements = ps.first;
	first_free = cap = ps.second;
	return *this;
}


// Just for test
StrVec genStrVec() {
	StrVec sv{"new", "old", "mountain"};
	return sv;
}

int main(int argc, char const *argv[]) {
	// StrVec sv;
	// sv = genStrVec();
	StrVec sv2 = genStrVec();
	
	for (const auto &word : sv2) {
		std::cout << word << " ";
	}
	std::cout << std::endl;
	return 0;
}
