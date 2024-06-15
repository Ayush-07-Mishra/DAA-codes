#include <iostream>
using namespace std;

class Node{
    public:
    int value;
    Node* next;
    Node* prev;

    public:
    Node(int value){
        this->value = value;
        Node* next = nullptr;
        Node* prev = nullptr;
    }
};

class DoublyLinkedList{
    private:
        Node* head;
        Node* tail;
        int length;

    public:
    DoublyLinkedList(int value){
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    void printList(){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void getHead(){
        cout << "Head: " << head->value << endl;
    }
    void getTail(){
        cout << "Tail : " << tail->value <<endl;
    }
    void getLength(){
        cout << "length : " << length << endl;
    }

    void append(int value){
        
    }
};

int main(){
    DoublyLinkedList* myDLL = new DoublyLinkedList(7);
    myDLL->getHead();
    myDLL->getTail();
    myDLL->getLength();
    myDLL->printList();
}