#include <iostream>
#include <string>

class Base {};
class Derived : public Base 
{
public:
	Derived() : name("Tom") {}
	
	void print()
	{
		std::cout << name << std::endl;
	}
private:
	std::string name;
};

int main(int argc, char const *argv[])
{
    // Derived &der = Base();  // error
    Derived &der = static_cast<Derived &>(Base());	// ok
    der.print();	// undefined
    
    return 0;
}
