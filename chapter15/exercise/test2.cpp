#include <iostream>

class MyClass
{
public:
    MyClass(const MyClass &)
    {
        std::cout << "MyClass copy constructot" << std::endl;
    }
    MyClass() = default;
};

MyClass createObject() {
    MyClass obj;
    // Initialize obj.
    return obj;
}

int main() {
    MyClass result = createObject();
}
