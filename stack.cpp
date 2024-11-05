#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int value) {
        this->value = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;
    int height;

public:
    // Constructor for an empty stack
    Stack() {
        top = nullptr;
        height = 0;
    }

    // Constructor for a stack initialized with a value
    Stack(int value) {
        top = new Node(value);
        height = 1;
    }

    void printStack() {
        Node* temp = top;
        while (temp) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void getTop() {
        if (top)
            cout << "Top: " << top->value << endl;
        else
            cout << "Stack is empty!" << endl;
    }

    void getHeight() {
        cout << "Height: " << height << endl;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        height++;
    }

    int pop() {
        if (height == 0) {
            cout << "Stack is empty!" << endl;
            return INT_MIN;  // Returning INT_MIN when the stack is empty
        }
        Node* temp = top;
        int poppedValue = top->value;
        top = top->next;
        delete temp;
        height--;
        return poppedValue;
    }
};

int main() {
    Stack* newStack = new Stack(4);  // Stack initialized with value 4
    newStack->push(5);  // Push 5 onto the stack
    newStack->getTop();  // Should print the top value (5)
    newStack->getHeight();  // Should print the height (2)
    
    cout << "Popped value: " << newStack->pop() << endl;  // Should pop 5 and print the popped value
    newStack->printStack();  // Should print the remaining stack (just 4)

    // Test case for empty stack
    cout << "Popped value: " << newStack->pop() << endl;  // Should pop 4 and print the popped value
    cout << "Popped value: " << newStack->pop() << endl;  // Should indicate the stack is empty (INT_MIN)
    
    return 0;
}
