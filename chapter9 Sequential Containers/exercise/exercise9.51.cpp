#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::invalid_argument;

class Date {
    unsigned year = 0;
    unsigned month = 0;
    unsigned day = 0;
    static vector<string> months;
    void convert(const string &word) {
        if (word.empty()) return;

        string::size_type p = 0;
        if (isdigit(word[0])) {
            unsigned n = std::stoi(word, &p);
            // check whether the characters of the word are all digit
            if (p != word.size()) {
                throw invalid_argument("Cannot convert the string to a date.");
            }
            month == 0 ? month = n : day == 0 ? day = n : year = n;
        } else {
            // check whether the word is a month string
            for (string::size_type index = 0, end = months.size();
                    index != end; ++index) {
                if (word.find(months[index]) != string::npos) {
                    month = month == 0 ? index + 1 : index;
                }
            }
            if (!month) throw invalid_argument("Cannot convert the string to a date.");
        }
    }
  public:
    Date() = default;
    Date(string const & s) {
        string word;
        for (auto c : s) {
            if (isalnum(c)) {
                word += c;
            } else {
                convert(word);
                word.clear();  
            }
        }
        convert(word);
    }
    unsigned get_year() const { return year; }
    unsigned get_month() const { return month; }
    unsigned get_day() const { return day; }

};

vector<string> Date::months{"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep",
                            "Oct", "Nov", "Dec"};

void print(const Date &dd) {
    cout << dd.get_year() << "/" << dd.get_month() << "/" << dd.get_day() << endl;
}

int main(int argc, char const *argv[])
{
    Date d1("February 17, 1932");
    Date d2("3/2/1983");
    Date d3("Aug 3, 1877");

    print(d1);
    print(d2);
    print(d3);
    return 0;
}
