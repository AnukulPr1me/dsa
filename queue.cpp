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

class Queue {
private:
    Node* first;
    Node* last;
    int length;

public:
    Queue(int value) {
        Node* newNode = new Node(value);
        first = newNode;
        last = newNode;
        length = 1;
    }

    void Enqueue(int value) {
        Node* newNode = new Node(value);

        if (length == 0) {
            first = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
        length++;
    }

    int Dequeue() {
        if (length == 0) return INT_MIN; // Queue is empty

        Node* temp = first;
        int dequeueValue = first->value;

        if (length == 1) {
            first = nullptr;
            last = nullptr;
        } else {
            first = first->next;
        }

        delete temp;
        length--;
        return dequeueValue;
    }

    void printQueue() {
        Node* temp = first;
        while (temp) {
            cout << " " << temp->value;
            temp = temp->next;
        }
        cout << endl;
    }

    void getFirst() {
        if (first) {
            cout << "First value: " << first->value << endl;
        } else {
            cout << "Queue is empty" << endl;
        }
    }

    void getLast() {
        if (last) {
            cout << "Last value: " << last->value << endl;
        } else {
            cout << "Queue is empty" << endl;
        }
    }

    void getLength() {
        cout << "Length: " << length << endl;
    }
};

int main() {
    Queue* myQueue = new Queue(8);
    myQueue->Enqueue(2);
    myQueue->printQueue();
    myQueue->getFirst();
    myQueue->getLast();
    myQueue->getLength();

    // Testing Dequeue
    cout << "Dequeue value: " << myQueue->Dequeue() << endl;
    myQueue->printQueue();
    myQueue->getFirst();
    myQueue->getLast();
    myQueue->getLength();

    delete myQueue;
    return 0;
}
