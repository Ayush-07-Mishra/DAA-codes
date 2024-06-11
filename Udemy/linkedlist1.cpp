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

    void deletelast() {
        if (head == nullptr) {
            cout << "Linked list is empty" << endl;
            return;
        }

        if (length == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
        }

        length--;
    }

    void deletefirst() {
        if (head == nullptr) {
            cout << "Linked list is empty" << endl;
            return;
        }

        if (length == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        length--;
    }

    void prepend(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    Node* get(int index){
        if(index < 0 || index >= length){
            return nullptr;
        }
        Node* temp = head;
        for(int i =0;i<index;i++){
            temp = temp->next;
        }
        return temp;
    }

    bool set(int index, int value) {
        Node* temp = get(index);
        if (temp) {
            temp->value = value;
            return true;
        } 
        return false;
    }

    bool insert(int index,int value){
        if(index < 0 || index >= length) return false;
        if(index == 0){
            prepend(value);
            return true;
        }
        if(index == length){
            append(value);
            return true;
        }
        Node* newNode = new Node(value);
        Node* temp = get(index - 1);
        newNode->next = temp->next;
        temp->next = newNode;
        length++;
        return true;
    }

    void deleteindex(int index){
        if(index < 0 || index > length) return;
        if(index == 0){
            deletefirst();
            return;
        }if(index == length - 1){
            deletelast();
            return;
        }
        Node* temp = get(index-1);
        Node* current = get(index);
        temp->next = current->next;
        delete current;
        length--;

    }

    void reverse(){
        Node* temp = head;
        head = tail;
        tail = temp;

        Node* after = temp->next;
        Node* before = nullptr;

        for(int i=0;i<length;i++){
            after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;
        }

    }

    ~LinkedList() {
        Node* temp = head;
        while (head) { // head != nullptr
            head = head->next;
            delete temp;
            temp = head;
        }
    }
};

int main() {
    LinkedList* myLinkedList = new LinkedList(1);

    myLinkedList->append(2);
    myLinkedList->append(3);
    myLinkedList->append(8);

    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();

    cout << "The linked list is:" << endl;
    myLinkedList->printList();

    myLinkedList->deletelast();
    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength(); 

    cout << "The linked list after deleting the last node is:" << endl;
    myLinkedList->printList();

    cout << "the value at index 1 is "<< myLinkedList->get(1)->value<< endl;
    myLinkedList->reverse();
    
    myLinkedList->printList();
    delete myLinkedList; // Clean up the allocated memory
}
