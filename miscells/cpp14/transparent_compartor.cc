#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {

  // struct Compartor {
  //   using is_transparent = void;
  //   bool operator()(int a, string b) const {
  //     return a < stoi(b);
  //   }
  // };

  vector<int> vi{12, 23, 44, 55, 99};
  if (lower_bound(vi.begin(), vi.end(), "55", [](const auto& a, const auto& b) {
    return a < stoi(b);
  }) != vi.end()) {
    cout << "success" << endl;
  } else {
    cout << "fail" << endl;
  }
  // std::find()
  return 0;
}