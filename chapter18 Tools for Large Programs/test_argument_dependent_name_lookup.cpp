#include <iostream>

namespace TT
{
	namespace DD
	{
		class Base
		{
		public:
			typedef int int32;
		};

		bool operator==(const Base &, const Base &);
	}

	// this funciton must be declared in the same namespace as the Base class
	// the defination must appear in the same or enclosing namespace of the declaration
	bool DD::operator==(const DD::Base &lhs, const DD::Base &rhs)
	{
		std::cout << "Base compare" << std::endl;
		return true;
	}
}

namespace YY
{
	class Derived : public TT::DD::Base
	{
		using TT::DD::Base::int32;
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
	b1 == b2;
	return 0;
}
