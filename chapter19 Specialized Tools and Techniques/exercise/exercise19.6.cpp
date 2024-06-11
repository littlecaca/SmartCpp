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
    Query_base *qp1 = new AndQuery;
    Query_base *qp2 = new OrQuery;

    if (AndQuery *ap = dynamic_cast<AndQuery *>(qp1))
    {
        cout << "yes" << endl;
    }
    
    if (AndQuery *ap = dynamic_cast<AndQuery *>(qp2))
    {
        
    }
    else
    {
        cout << "no" << endl;
    }


    return 0;
}
