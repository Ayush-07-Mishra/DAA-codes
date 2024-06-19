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

class Stack{
    private:
        Node* top;
        int height;

    public:
        Stack(int value){
            Node* newNode = new Node(value);
            top = newNode;
            height = 1;
        }
        
        void printStack(){
            Node* temp = top;

            while(temp){
                cout<< temp->value << endl;
                temp = temp->next;
            }
        }

        void getTop(){
            cout <<"top : "<< top->value << endl;
        }

        void getHeight(){
            cout <<"Height : "<< height << endl;
        }

        void push(int value){
            Node* newNode = new Node(value);
            // if(top == nullptr){     //not neccesary as it doesnt have head and tail sepeartly 
            //     top = newNode;
            // }else{
            //     newNode->next = top;
            //     top = newNode;
            // }
            newNode->next = top;
            top = newNode;
            height++;
            return;
        }

        int pop(){
            if(height == 0){
                return INT_MIN; // important 
            }
            Node* temp = top;
            int popedvalue = top->value;
            top = top->next;
            delete temp;
            height --;
            return popedvalue;
        }
};

int main(){
    Stack* mystk = new Stack(4);
    mystk->getTop();
    mystk->getHeight();
    mystk->printStack();
    mystk->push(3);
    mystk->push(2);
    mystk->getTop();
    mystk->getHeight();
    mystk->pop();
    mystk->printStack();

}