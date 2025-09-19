#pragma once

#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

#include "calcultors.h"

enum NodeType {
  CONSTANT = 0,
  VARIAVBLE = 1,
  EXPRESSION = 2,
  ZERO = 3,
};

class Node {
  friend class Absolute;
public:
  Node(NodeType type, const std::string &name = "", double val = 0.0)
      : type_(type), name_(name), val_(val) {}

  Node operator+(const Node &rhs) const {
    if (type_ == ZERO) {
      return rhs;
    }
    if (rhs.type_ == ZERO) {
      return *this;
    }
    return Register(Add::GetInstance(), rhs);
  }

  Node operator-(const Node &rhs) const{
    if (rhs.type_ == ZERO) {
      return *this;
    }
    return Register(Sub::GetInstance(), rhs);
  }

  Node operator*(const Node &rhs) const {
    if (type_ == ZERO || rhs.type_ == ZERO) {
      return Node(ZERO, "", 0);
    }
    return Register(Multi::GetInstance(), rhs);
  }

  Node operator/(const Node &rhs) const {
    if (type_ == ZERO) {
      return Node(ZERO, "", 0);
    }
    return Register(Divide::GetInstance(), rhs);
  }

  Node pow2() const {
    return *this * *this;
  }

  Node abs() const {
    if (type_ == ZERO) {
      return *this;
    }
    return Register(Absolute::GetInstance(), *this);
  }

public:
  // 求值-前向预测
  double Evaluate(const std::unordered_map<std::string, double> &feed) const {
    if (type_ == NodeType::CONSTANT || type_ == ZERO) {
      return val_;
    }
    if (type_ == NodeType::VARIAVBLE) {
      auto it = feed.find(name_);
      if (it == feed.end()) {
        throw std::runtime_error("can not find " + name_ + "'s value");
      }
      return it->second;
    }
    std::vector<double> inputs;
    for (auto &depend : depends_) {
      inputs.push_back(depend.Evaluate(feed));
    }
    
    return cal_->forward(inputs);
  }

  // 获取导数表达式
  Node Derivative(const std::string &tar) const {
    if (type_ == CONSTANT || type_ == ZERO) {
      return Node(ZERO, "", 0);
    }
    if (type_ == VARIAVBLE) {
      if (name_ == tar) {
        return Node(NodeType::CONSTANT, "", 1);
      } else {
        return Node(NodeType::ZERO, "", 0);
      }
    }
    return cal_->derivative(depends_, tar);
  }

public:
  Node Register(Calculator* cal, const Node &other) const {
    Node val(NodeType::EXPRESSION);
    val.cal_ = cal;
    val.depends_.push_back(*this);
    val.depends_.push_back(other);
    return val;
  }

  Node Register(Calculator* cal) const {
    Node val(EXPRESSION);
    val.cal_ = cal;
    val.depends_.push_back(*this);
    return val;
  }

private:
  NodeType type_;
  std::string name_;
  double val_;
  Calculator* cal_;
  std::vector<Node> depends_;
};

class Cons : public Node {
public:
  Cons(double val) : Node(CONSTANT, "", val) {}
};

class Vari : public Node {
public:
  Vari(const std::string &name) : Node(VARIAVBLE, name) {}
};
