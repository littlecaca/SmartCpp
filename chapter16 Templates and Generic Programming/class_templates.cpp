#include <initializer_list>
#include <vector>
#include <memory>
#include <iterator>

/*
 * A class template is a blueprint for generating classes.
 * The compiler can not deduce the template parameter types for a class template.
 * We must supply a list of explicit template arguments to instaintiate the class template.
 * 
 * Define a Class Template
 * 
 * Instantiating a Class Template
 * 
 * Reference to a Template Type in the Scope of the Template
 * 
 * We often use the template's own parameter(s) as the template arguments(s):
 * 
 * Blob<T>   ---> std::shared_ptr<std::vector<T>> data;
 *      ^                               ^
 *      |                               |
 *   parameter                       argument
 * 
 * 
 * 
 * Member Functions of Class Templates
 * 
 * Each instantiation of the class template has its own version of each member.
 * As a result, a member function of a class template has the same template parameters as the class
 * itself. Therefore, a member function defined outside the class template body starts
 * with the keyword template followed by the class’ template parameter list.
 * 
 * 
 */


template <typename T>
class Blob
{
public:
    template <typename It>
    Blob(It begin, It end) : data(std::make_shared<std::vector<T>>(begin, end)) {}
    Blob() : data(new std::vector<T>) {}
    Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il)) {}

private:
    std::shared_ptr<std::vector<T>> data;
};

int main(int argc, char const *argv[])
{
    /* code */
    int nums[] = {1 ,2};
    Blob<int>(std::begin(nums), std::end(nums));
    return 0;
}
