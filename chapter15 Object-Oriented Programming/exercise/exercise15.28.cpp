#include <vector>
#include <memory>
#include "Quote.h"

int main(int argc, char const *argv[])
{
    std::vector<Exe::Quote> vq;
    vq.push_back(Exe::Bulk_quote("123", 12, 12, 0.4));
    std::cout << vq.back().net_price(88) << std::endl;

    std::vector<std::shared_ptr<Exe::Quote>> vsq;
    vsq.push_back(std::make_shared<Exe::Bulk_quote>("123", 12, 12, 0.4));
    std::cout << vsq.back()->net_price(88) << std::endl;
    
    return 0;
}

