#include <iostream>

namespace TT
{
	namespace DD
	{
		class Base
		{

		};

	}

	bool operator==(const DD::Base &lhs, const DD::Base &rhs)
	{
		std::cout << "Base compare" << std::endl;
		return true;
	}

}

namespace YY
{
	class Derived : public TT::DD::Base
	{

	};
}

bool operator==(const YY::Derived &lhs, const YY::Derived &rhs)
{
	std::cout << "Derived compare" << std::endl;
	return true;
}


int main(int argc, char const *argv[])
{
	/* code */
	YY::Derived d1, d2;
	TT::DD::Base b1, b2;
	d1 == d2;
	// b1 == b2;
	return 0;
}
