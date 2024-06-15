#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node* prev;

    Node(int value) {
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    DoublyLinkedList(int value) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void getHead() {
        cout << "Head: " << head->value << endl;
    }
    void getTail() {
        cout << "Tail : " << tail->value << endl;
    }
    void getLength() {
        cout << "length : " << length << endl;
    }

    void append(int value) {
        Node* newNode = new Node(value);

        if (length == 0) { // or head == nullptr
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }

    void deletelast() {
        if (length == 0) {
            return;
        } else if (length == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
            length--;
        } else {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
            length--;
        }
    }

    void prepend(int value) {
        Node* newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        length++;
    }

    void deletefirst() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        length--;
    }

    Node* get(int index) {
        if (index < 0 || index >= length) {
            return nullptr;
        }
        Node* temp = head;
        if (index < (length / 2)) {
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
        } else {
            temp = tail;
            for (int i = length - 1; i > index; i--) {
                temp = temp->prev;
            }
        }
        return temp;
    }

    bool set(int value, int index) {
        Node* temp = get(index);
        if (temp != nullptr) {
            temp->value = value;
            return true;
        }
        return false;
    }

    bool insert(int value, int index) {
        if (index < 0 || index > length) {
            return false;
        }
        if (index == 0) {
            prepend(value);
            return true;
        }
        if (index == length) {
            append(value);
            return true;
        }

        Node* newNode = new Node(value);
        Node* before = get(index - 1);
        Node* after = before->next;
        before->next = newNode;
        newNode->prev = before;
        newNode->next = after;
        if (after != nullptr) {
            after->prev = newNode;
        }
        length++;
        return true;
    }

    void deleteNode(int index) {
        if (index < 0 || index >= length) {
            return;
        }
        if (index == 0) {
            deletefirst();
            return;
        }
        if (index == length - 1) {
            deletelast();
            return;
        }
        Node* temp = get(index);
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        length--;
    }
};

int main() {
    DoublyLinkedList* myDLL = new DoublyLinkedList(1);
    myDLL->append(2);
    myDLL->append(3);
    myDLL->append(4);
    myDLL->append(5);
    myDLL->append(6);
    myDLL->deletelast();
    myDLL->deletefirst();
    myDLL->getHead();
    myDLL->getTail();
    myDLL->getLength();
    myDLL->get(3);
    myDLL->deleteNode(2);
    myDLL->printList();
myDLL->getLength();
    delete myDLL;  // Ensure we clean up the allocated memory for the list
    return 0;
}
