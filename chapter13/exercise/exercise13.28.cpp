#include <iostream>
#include <string>

//          +------------------------+
//          |     (a) TreeNode       |
//          +------------------------+

class TreeNode {
    // Realise the value like copy-control members
  public:
    TreeNode(const std::string &s = std::string())
        : value(s), count(1), left(nullptr), right(nullptr) {}
    TreeNode(const TreeNode &node);
    TreeNode &operator=(TreeNode &);
    ~TreeNode();
    TreeNode *setLeft(TreeNode *);
    TreeNode *setRight(TreeNode *);

    TreeNode &getLeft() const { return *left; }
    TreeNode &getRight() const { return *right; }
    std::string value;

  private:
    int count; // the number of external references
    TreeNode *left;
    TreeNode *right;
};

TreeNode::TreeNode(const TreeNode &node)
    : value(node.value), count(1) {
        left = node.left == nullptr ? nullptr : new auto(*node.left);
        right = node.right == nullptr ? nullptr : new auto(*node.right);
    }

TreeNode &TreeNode::operator=(TreeNode &node) {
    value = node.value;

    auto temp_left = left;
    auto temp_right = right;

    left = node.left == nullptr ? nullptr : new auto(*node.left);
    right = node.right == nullptr ? nullptr : new auto(*node.right);
    
    if (temp_left)
        delete temp_left;
    if (temp_right)
        delete temp_right;
    return *this;
}

TreeNode::~TreeNode() {
    std::cout << "delete : " << value << std::endl;
    if (--count == 0) {
        if (left)
            delete left;
        if (right)
            delete right;
    }
}

TreeNode *TreeNode::setLeft(TreeNode *pNode) { 
    auto temp_left = left;
    left = pNode;
    if (temp_left)
        delete temp_left;
    return left;
}

TreeNode *TreeNode::setRight(TreeNode *pNode) { 
    auto temp_right = right;
    right = pNode;
    if (temp_right)
        delete temp_right;
    return right;
}


//      +-----------------------+
//      |    (b) BinStrTree     |
//      +-----------------------+


class BinStrTree {
  public:
    // Constructor
    BinStrTree() : root(new TreeNode("root")) {}
    BinStrTree(const std::string &v) : root(new TreeNode(v)) {}
    BinStrTree(TreeNode *pNode) : root(pNode) {}    // pointer-like
    // Copy control members
    BinStrTree(const BinStrTree &tree) : root(new auto(*tree.root)) {};
    BinStrTree &operator=(const BinStrTree &);
    ~BinStrTree() { delete root; };

    TreeNode &getRoot() const { return *root; }
  private:
    TreeNode *root;
};

BinStrTree &BinStrTree::operator=(const BinStrTree &tree) {
    *root = *tree.root;
    return *this;
}


int main(int argc, char const *argv[]) {
    TreeNode *t1 = new TreeNode("t1");

    t1->setLeft(new TreeNode("t2"))->setRight(new TreeNode("t3"));
    t1->setRight(new TreeNode("t4"));


    std::cout << t1->value << std::endl;
    std::cout << t1->getLeft().value << std::endl;
    std::cout << t1->getRight().value << std::endl;
    std::cout << t1->getLeft().getRight().value << std::endl;

    BinStrTree bt(t1), bt2;
    bt2 = bt;
    BinStrTree bt3(bt2);
    // Free the memory automatically


    return 0;
}
