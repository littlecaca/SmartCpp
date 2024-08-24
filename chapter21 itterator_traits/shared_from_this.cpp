#include <boost/enable_shared_from_this.hpp>

template <class T>
class Base : public boost::enable_shared_from_this<T>
{

};