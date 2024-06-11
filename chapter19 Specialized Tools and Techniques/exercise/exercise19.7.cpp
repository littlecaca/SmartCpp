#include <iostream>

using namespace std;


class Query_base
{
public:
    virtual ~Query_base() {}
};

class AndQuery : public Query_base
{

};

class OrQuery : public Query_base
{

};

int main(int argc, char const *argv[])
{
    Query_base qb;

    try
    {
        AndQuery &ar = dynamic_cast<AndQuery &>(qb);
    }
    catch(const std::bad_cast& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}
