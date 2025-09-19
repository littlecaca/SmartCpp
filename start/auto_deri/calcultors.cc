#include "calcultors.h"
#include "node.h"
#include <iterator>
#include <stdexcept>

Node Calculator::derivative(const std::vector<Node> &depends, const std::string &tar) {
    if (depends.size() < depend_num()) {
        throw std::runtime_error("absent depends");
    }
    return inner_deri(depends, tar);
}

Node Add::inner_deri(const std::vector<Node> &depends, const std::string &tar) {
    return depends[0].Derivative(tar) + depends[1].Derivative(tar);
}

Node Sub::inner_deri(const std::vector<Node> &depends, const std::string &tar) {
    return depends[0].Derivative(tar) - depends[1].Derivative(tar);
}

Node Multi::inner_deri(const std::vector<Node> &depends, const std::string &tar) {
    return depends[0].Derivative(tar) * depends[1] + depends[0] * depends[1].Derivative(tar);
}

Node Divide::inner_deri(const std::vector<Node> &depends, const std::string &tar) {
    return (depends[0].Derivative(tar) * depends[1] - depends[0] * depends[1].Derivative(tar))
        / depends[1].pow2();
}

Node Absolute::inner_deri(const std::vector<Node> &depends, const std::string &tar) {
    Node val(NodeType::EXPRESSION);
    val.cal_ = this;
    val.depends_.push_back(depends[0].Derivative(tar));
    val.depends_.push_back(depends[1]);
    return val;
}
