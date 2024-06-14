#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>

class Sales_data
{
public:
    Sales_data(double pri) : price(pri) {}
    bool greater(double rhs) const noexcept
    {
        return price > rhs;
    }

    double getPrice() const noexcept
    {
        return price;
    }

private:
    double price;
};

int main(int argc, char const *argv[])
{
    std::vector<Sales_data> vs{Sales_data(0.1), Sales_data(0.4)};
    auto it = std::find_if(vs.begin(), vs.end(), 
        std::bind(&Sales_data::greater, std::placeholders::_1, 0.3));
    std::cout << it->getPrice() << std::endl;
    return 0;
}
