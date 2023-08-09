#include <vector>

std::vector<int> get_vc() {
    return std::vector<int> {1, 2, 3, 4, 5};
}

int main(int argc, char const *argv[])
{
    std::vector<int> t = get_vc();
    return 0;
}
