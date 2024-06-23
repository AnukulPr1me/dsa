#include <iostream>

using namespace std;

class Node {
  public:
    int value;
    Node* next;
  Node(int value) {
    this-> value = value;
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
      head = newNode;
      tail = newNode;
      length = 1;
    }

  void printList() {
    Node* temp = head;
    while (temp) {
      cout << temp->value;
      temp = temp->next;
    }
  }
  void getHead() {
    cout << "Head " << head->value;
  }
  void getTail() {
    cout << "Tail " << tail->value;
  }
  void getLength() {
    cout << "Length " << length;
  } void append(int value) {

    Node* newNode = new Node(value);

    if(length == 0) {
      head = newNode;
      tail = newNode;
    }
    else {
      tail->next = newNode;
      tail = newNode;
    }
    length++;
  }
};

int main() {
  LinkedList* newLinkedList = new LinkedList(4);

  newLinkedList->printList();

  newLinkedList->append(5);

  newLinkedList->getLength();

  newLinkedList->printList();
  
}


