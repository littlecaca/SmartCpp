#include <set>
#include <memory>

int main(int argc, char const *argv[])
{
    typedef std::unique_ptr<int> Entry;
    std::set<Entry> si;

    si.emplace(new int(2));
    Entry e = std::move(const_cast<Entry &>(*si.begin()));
    
    return 0;
}
