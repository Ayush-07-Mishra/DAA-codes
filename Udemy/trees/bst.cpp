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

    bool insert(int value){
        Node* newNode = new Node(value);
        
        if(root == nullptr){
            root = newNode;
        }else{
            Node* temp = root;
            while(true){
                if(newNode->value == temp->value){
                    return false;
                }
                if(newNode->value < temp->value){
                    if(temp->left == nullptr){
                        temp->left = newNode;
                        return true;
                    }
                    temp = temp->left;
                }else{
                    if(temp->right == nullptr){
                        temp->right = newNode;
                        return true;
                    }
                    temp = temp->right;
                }
            }
        }
    }

    bool contains(int value) {
        Node* temp = root;

        while (temp != nullptr) {
            if (value == temp->value) {
                return true;
            } else if (value < temp->value) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }

        return false;
    }
};

int main() {
    BinarySearchTree* bst = new BinarySearchTree();
    cout << "root : " << bst->root << endl;

    bst->insert(2);
    bst->insert(3);
    bst->insert(1);
    cout << "root : " << bst->root->value << endl;
    cout << "left : "<<bst->root->left->value << endl;
    cout << "right : "<< bst->root->right->value << endl;

    cout << bst->contains(2) << endl;
    cout << bst->contains(4) << endl;

    delete bst;

    return 0;
}
