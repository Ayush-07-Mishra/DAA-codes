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
        Node* last;
        int length;

    public:
        Queue(int value){
            Node* newNode = new Node(value);
            first = newNode;
            last = newNode;
            length = 1;
        }

        void printQueue(){
            Node* temp = first;
            while(temp){
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        void getLength(){
            cout << "Length : " << length <<endl;
        }
        void getFirst(){
            cout << "First : " << first->value << endl;
        }
        void getLast(){
            cout << "Last : " << last->value << endl;
        }

        void Enqueue(int value){
            Node* newNode = new Node(value);
            if(length == 0){
                first = newNode;
                last = newNode;
            }else{
                last->next = newNode;
                last = newNode;
            }
            length++;
        }

        int Dequeue(){
            Node* temp = first;
            if(length == 0){
                return INT_MIN;
            }if(length == 1){
                first == nullptr;
                last == nullptr;
            }else{
               first = first->next; 
            }
            return temp->value;
            length--;
            delete temp;
                
            
        }

};
int main(){
    Queue* myQ = new Queue(7);
    myQ->getFirst();
    myQ->getLast();
    myQ->getLength();
    myQ->printQueue();
    myQ->Enqueue(1);
    myQ->Enqueue(4);
    myQ->Enqueue(2);
    myQ->getFirst();
    myQ->getLast();
    myQ->getLength();
    myQ->printQueue();
    myQ->Dequeue();
    myQ->getFirst();
    myQ->getLast();
    myQ->getLength();
    myQ->printQueue();
}