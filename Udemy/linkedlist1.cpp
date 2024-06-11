#include <iostream>
using namespace std;

class Node {
    public:
        int value;
        Node* next;
    public:
        Node(int value) {
            this->value = value;
            next = nullptr;
        }
};

class LinkedList {
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);

            head = newNode; // Initialize head
            tail = newNode; // Initialize tail
            length = 1;     // Initialize length
        }

        void printList() {
            Node* temp = head;
            while (temp) { // temp != nullptr
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        void getHead() {
            if (head) {
                cout << "Head: " << head->value << endl;
            } else {
                cout << "Head: null" << endl;
            }
        }

        void getTail() {
            if (tail) {
                cout << "Tail: " << tail->value << endl;
            } else {
                cout << "Tail: null" << endl;
            }
        }

        void getLength() {
            cout << "Length: " << length << endl;
        }

        ~LinkedList(){
            Node* temp = head;
            while(head){ // head != nullptr
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void append(int val) {
            Node* newNode = new Node(val);
            if (head == nullptr) { // if the list is empty
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            length++;
        }

        void delete()

};



int main() {
    LinkedList* myLinkedList = new LinkedList(1);

    myLinkedList->append(2);
    myLinkedList->append(3);
    myLinkedList->append(8);

    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();

    cout << "the linkedlist is" << endl;
    myLinkedList->printList();

    delete myLinkedList; // Clean up the allocated memory
}
