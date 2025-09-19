#pragma once

#include <cstdlib>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <memory>
#include <cmath>

class Node;

class Calculator {
public:
  double forward(const std::vector<double> &inputs) {
    if (inputs.size() < depend_num()) {
      throw std::runtime_error("absent inputs");
    }
    return inner_forward(inputs);
  }

  Node derivative(const std::vector<Node> &depends, const std::string &tar);

public:
  Calculator() = default;
  
private:
  virtual double depend_num() { return 2; }
  virtual double inner_forward(const std::vector<double> &inputs) = 0;
  virtual Node inner_deri(const std::vector<Node> &depends, const std::string &tar) = 0;

private:
  Calculator(const Calculator &) = delete;
  Calculator &operator=(const Calculator &) = delete;
};

template <typename T> struct Singleton {
  static T *GetInstance() {
    static T t;
    return &t;
  }
};

class Add : public Calculator, public Singleton<Add> {
  double inner_forward(const std::vector<double> &inputs) override {
    return inputs[0] + inputs[1];
  }
  Node inner_deri(const std::vector<Node> &depends, const std::string &tar) override;
};

class Sub : public Calculator, public Singleton<Sub> {
  double inner_forward(const std::vector<double> &inputs) override {
    return inputs[0] - inputs[1];
  }
  Node inner_deri(const std::vector<Node> &depends, const std::string &tar) override;
};

class Multi : public Calculator, public Singleton<Multi> {
  double inner_forward(const std::vector<double> &inputs) override {
    return inputs[0] * inputs[1];
  }
  Node inner_deri(const std::vector<Node> &depends, const std::string &tar) override;
};

class Divide : public Calculator, public Singleton<Divide> {
  double inner_forward(const std::vector<double> &inputs) override {
    return inputs[0] / inputs[1];
  }
  Node inner_deri(const std::vector<Node> &depends, const std::string &tar) override;
};

class Absolute : public Calculator, public Singleton<Absolute> {
  double inner_forward(const std::vector<double> &inputs) override {
    return inputs[1] > 0 ? inputs[0] : -inputs[0]; 
  }
  Node inner_deri(const std::vector<Node> &depends, const std::string &tar) override;
};

