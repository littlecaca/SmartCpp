#include <memory>
#include <vector>
#include <string>
#include <iostream>

class Base
{
public:
	virtual void test() const
	{
		std::cout << "I am the Base class" << std::endl;
	};
};

class Derived : public Base
{
private:
	void test() const
	{
		std::cout << "I an the Derived class" << std::endl;
	}
};

class Test
{
public:
	Test() = default;
	Test(const Test &)
	{
		std::cout << "Base copy constructor" << std::endl;
	}
	Test(Test &&) = delete;
};

class DTest : public Test
{
};

int main(int argc, char const *argv[])
{
	DTest t;
	// DTest t2(t);
	DTest t3(std::move(t));

	// const Base &base = Derived();
	// base.test();
	std::shared_ptr<std::vector<std::string>> s{};
	if (s == nullptr)
		std::cout << "yes" << std::endl;

	return 0;
}
