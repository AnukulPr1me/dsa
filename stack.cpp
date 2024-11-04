#include <iostream>

using namespace std;

class Node {
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
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void getTop(){
        cout << "Top: " << top->value << endl;
    }

    void getHeight(){
        cout << "Height: " << height << endl;
    }

};

int main(){
    Stack* newStack = new Stack(4);
    newStack->getTop();
    newStack->getHeight();
    newStack->printStack();

}

