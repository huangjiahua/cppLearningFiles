#include <iostream>
#include <string>

using namespace std;

class TreeNode {
public:
    TreeNode(): value(string()), count(new int(1)), left(nullptr),
        right(nullptr) { }
    TreeNode(const TreeNode &org): value(org.value), count(org.count),
        left(org.left), right(org.right) { ++*count; }
    TreeNode operator=(const TreeNode &org) {
        ++*org.count;
        if (--*count == 0) {
            if (right) {
                delete right;
                right = nullptr;
            }
            if (left) {
                delete left;
                left = nullptr;
            }
            delete count;
            count = nullptr;
        }
        value = org.value;
        left = org.left;
        right = org.right;
        count = org.count;
        return *this;
    }
    ~TreeNode() {
        if (--*count == 0) {
            if (right) {
                delete right;
                right = nullptr;
            }
            if (left) {
                delete left;
                left = nullptr;
            }
            delete count;
            count = nullptr;
        }
    }
private:
    string value;
    int *count;
    TreeNode *left;
    TreeNode *right;
};

class BinStrTree {
public:
    BinStrTree(TreeNode tree): root(new TreeNode()) { }
    BinStrTree(const BinStrTree &org): root(new TreeNode(*org.root)) { }
    BinStrTree operator=(const BinStrTree &org)
    {
        auto newp = new TreeNode(*org.root);
        delete root;
        root = newp;
        return *this;
    }
    ~BinStrTree()
    {
        delete root;
    }
private:
    TreeNode *root;
};
