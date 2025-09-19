#include <iostream>
#include <unordered_map>

#include "node.h"

using namespace std;

// 自定义通用算子 exp， 示范
class Exp : public Calculator, public Singleton<Exp> {
public:
  static Node exponent(const Node &rhs) {
    return rhs.Register(Exp::GetInstance());
  }

private:
  double inner_forward(const std::vector<double> &inputs) override {
    return std::exp(inputs[0]);
  }

  Node inner_deri(const std::vector<Node> &depends, const std::string &tar) override {
    return exponent(depends[0]) * depends[0].Derivative(tar);
  };

  double depend_num() override { return 1; }
};


int main() {
  std::unordered_map<std::string, double> feed {
    {"x", 3},
    {"y", -24},
    {"z", 4}
  };

  // 测试+ * pow2 / abs
  std::cout << "testcase1" << std::endl;
  auto expre = Vari("x").pow2() * Vari("y").abs() + Cons(-14.5).abs() / Vari("z");

  auto deri = expre.Derivative("x");
  auto deri2 = deri.Derivative("x");
  // x^2 * abs(y) + 13.4 / z
  std::cout << expre.Evaluate(feed) << std::endl;
  // 2 * x *abs(y)
  std::cout << deri.Evaluate(feed) << std::endl;
  // 2 * abs(y)
  std::cout << deri2.Evaluate(feed) << std::endl;
  
  // 测试- pow2 abs
  std::cout << "testcase2" << std::endl;
  auto expre2 = Cons(-19.2).abs() - Vari("x").pow2();
  deri2 = expre2.Derivative("x");
  std::cout << expre2.Evaluate(feed) << std::endl;
  std::cout << deri2.Evaluate(feed) << std::endl;

  // 测试abs
  std::cout << "testcase3" << std::endl;
  auto expre3 = Vari("y").pow2().abs();
  auto deri3 = expre3.Derivative("y");
  std::cout << expre3.Evaluate(feed) << std::endl;
  std::cout << deri3.Evaluate(feed) << std::endl;

  // 测试exp
  std::cout << "testcase4" << std::endl;
  auto expre_exp = Exp::exponent(Vari("x"));
  auto exp_deri = expre_exp.Derivative("x");
  std::cout << expre_exp.Evaluate(feed) << std::endl;
  std::cout << exp_deri.Evaluate(feed) << std::endl;
  return 0;
}
