#include <vector>
#include <memory>
#include <exception>

using namespace std;


template <typename T>
class Blob
{
public:
    Blob(std::initializer_list<T>);

    std::shared_ptr<vector<T>> data;
};

void handle_out_of_memory(const std::exception &e)
{
}

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il)
try : data(std::make_shared<std::vector<T>>(il))
{
    /* empty body */
}
catch (const std::bad_alloc &e)
{
    handle_out_of_memory(e);
}