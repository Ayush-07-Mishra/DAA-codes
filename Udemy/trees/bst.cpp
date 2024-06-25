#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() {
        root = nullptr;
    }
};

int main() {
    BinarySearchTree* bst = new BinarySearchTree();
    cout << "root : " << bst->root << endl;

    return 0;
}
