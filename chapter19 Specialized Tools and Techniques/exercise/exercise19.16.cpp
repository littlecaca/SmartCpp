#include <string>

class Sales_data
{
public:
    std::string bookNo;
    double avg_price;
};

int main(int argc, char const *argv[])
{
    const double Sales_data::*pdata = &Sales_data::avg_price;

    return 0;
}
