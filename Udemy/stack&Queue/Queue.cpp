#include<iostream>

using namespace std;

class Node{
    public:
        int value;
        Node* next;

        Node(int value){
            this->value = value;
            next = nullptr;
        }
};

class Queue{
    private:
        Node* first;
        Node* Last;
        int length;

    public:
        Queue(int value){
            Node* newNode = new Node(value);
            first = newNode;
            Last = newNode;
            length = 1;
        }

};
int main(){
    
}