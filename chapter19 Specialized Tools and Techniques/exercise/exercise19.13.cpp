#include <string>

class Sales_data
{
public:
    std::string bookNo;
};

int main(int argc, char const *argv[])
{
    
    const std::string Sales_data::*pbookNo = &Sales_data::bookNo;
    
    return 0;
}
