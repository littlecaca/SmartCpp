#include <iomanip>
#include <exception>
#include <string>
#include <iostream>

using namespace std;

class isbn_mismatch : public std::logic_error
{
public:
    isbn_mismatch(const string &desc) : logic_error(desc) {}
    isbn_mismatch(const string &desc, const string &_lhs, const string &_rhs)
        : logic_error(desc), lhs(_lhs), rhs(_rhs) {}

    const char *what() const noexcept override
    {
        return "The isbn of books must be the same to execute this operation!";
    }

private:
    string lhs;
    string rhs;
};

class empty_record : public std::runtime_error
{
public:
    empty_record(const string &desc) : runtime_error(desc) {}
};

struct Sales_data
{
    Sales_data &operator+=(const Sales_data &);

    std::string isbn;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data &Sales_data::operator+=(const Sales_data &rhs)
{
    if (isbn != rhs.isbn)
        throw isbn_mismatch("The lhs and rhs's isbns are not the same");
    if (isbn.empty() || rhs.isbn.empty())
        throw empty_record("The lhs or rhs has a empty isbn");

    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

ostream &operator<<(ostream &os, const Sales_data &sale)
{   
    os << left;
    os << "(" << setw(10) << sale.isbn
       << setw(6) << sale.units_sold << setprecision(2) << fixed 
       << setw(6) << sale.revenue << ")";
    os << right;
    return os;
}

istream &operator>>(istream &is, Sales_data &sale)
{
    cout << "Please input isbn, units_sold, revenue orderly:" << endl;
    is >> sale.isbn >> sale.units_sold >> sale.revenue;
    cout << "complete" << endl;
    return is;
}

int main(int argc, char const *argv[])
{
    Sales_data s1, s2;
    cin >> s1 >> s2;
    s1 += s2;
    cout << s1 << endl;
    return 0;
}
