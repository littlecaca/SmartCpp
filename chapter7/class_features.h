#include <iostream>
#include <string>
#include <vector>
/*
 * Defining a Type Member
 *
 * Unlike ordinary members, members that define types must appear before they are used. As
 * a result, type members usually appear at the begining of the class.
 * 
 * 
 * Making Members inline
 * 
 * 
 * `mutable` Data Members
 * 
 * We indicates members which can be modified even inside a const member function by including
 * the `mutable` keyword in their declaration. A mutable data member is never const, even when
 * it is a member of a const object. 
 * 
 * 
 * Initializers for Data Members of Class type
 * 
 * When we initialize a member of class type, we are supplying arguments to a constructor of 
 * that member's type.
 * 
 * 
 * Returning *this from a const Member Function
 * 
 * A const member function that returns *this as a reference should have a return type that is
 * a reference to const.
 * 
 * 
 * Overloading Based on const
 * 
 * 
 * Advice: Use Private Utility Functions For Common Code
 * 
 * 
 * We can use the class name following the keyword class or struct.
 * 
 * 
 * Class Declarations
 * 
 * After a declaration and before a definition is seen, the type Screen is an incomplete type--
 * it's known that Screen is a class type but not known what members that type contains. We can use
 * an incomplete type in only limited ways: We can define pointers or references to such types,
 * and we can declare (but not define) functions that use an incomplete type as a parameter or return type.
 * 
 * 
 * Friendship Revisited
 * 
 * A class also make another class its friend or it can declare specific member functions of another
 * (previously defined) class as friends. In addition, a friend function cam be defined inside the class
 * body. Such functions are implicitly inline.
 * 
 * 
 * Note the structuring of our programs to accommodate interdependencies among the declarations and
 * definitions.
 * 
 * 
 * Overloaded Functions and Friendship
 * 
 * 
 * Friend Declarations and Scope
 * 
 * Classes and nonmember functions need not have been declared before they are used in a friend declaration.
 * When a name first appears in a friend declaration, that name is implicitly assumed to be part of the
 * surrounding scope. However, the friend itself is not actually declared in that scope. Even if we define
 * the function inside the class, we must still provide a declaraiton outside of the class itself to make that
 * function visible. A declaration must exist even if we only call the friend from members of the friendship
 * granting class.
 * 
 * 
 * Scope and Members Defined outside the Class
 */

#ifndef CLASS_FEATURES_H
#define CLASS_FEATURES_H

class Screen;
// initializers for data member of class type
class Window_mgr { 
  public:
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(ScreenIndex);
	ScreenIndex addScreen(const Screen &);
  private:
    std::vector<Screen> screens{Screen(24, 80, ' ')};
    
};


class Screen {
	// friend class Window_mgr;
	friend void Window_mgr::clear(ScreenIndex);
  public:
    using pos = std::string::size_type;
    Screen() = default;     // needed because Screen has another constructor
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
    char get() const { return contents[cursor]; }   // implicitly inline
    inline char get(pos ht, pos wd) const;          // explicitly inline
    Screen &move(pos r, pos c);                     // can be made inline later
    void some_member() const;

    Screen &set(char);
    Screen &set(pos, pos, char);

	pos size() const;

    // overloading based on const
    Screen &display(std::ostream &os) { do_display(os); return *this; }
    const Screen &display(std::ostream &os) const { do_display(os); return *this; }
  private:
    mutable size_t access_ctr = 0;
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

    void  do_display(std::ostream &os) const;
};

void Screen::some_member() const {
    ++access_ctr;
}

// we can specify inline on the definition
inline Screen &Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

// declared as inline in the class
// it is legal to specify inline on both the declaration and definition
// however, specifying inline only on the definition outside the class can make the class easier to read
char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}

// functions that return *this
inline Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch) {
    contents[r * width + col] = ch;
    return *this;
}

void Screen::do_display(std::ostream &os) const {
	for (pos c = 0; c < width; ++c) {
		os << contents[c];
	}
	for (pos r = 1; r < height; ++r) {
		os << "\n";
		pos row = r * width;
		for (pos c = 0; c < width; ++c) {
			os << contents[row + c];
		}
	}
}

inline Screen::pos Screen::size() const {
	return height * width;
}


// because class Window_mgr is a friend of class Screen, so the members of Window_mgs can access the
// private data members of Screen. The friendship is not transitive.
void Window_mgr::clear(ScreenIndex i) {
	Screen &s = screens[i];
	s.contents = std::string(s.height * s.width, ' ');
}

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s) {
	screens.push_back(s);
	return screens.size() - 1;
}

#endif

