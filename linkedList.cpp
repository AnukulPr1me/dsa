#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int value)
    {
        this->value = value;
        this->next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int length;

public:
    LinkedList(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }
    void printList()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void getHead()
    {
        cout << "Head: " << head->value << endl;
    }

    void getTail()
    {
        cout << "Tail: " << tail->value << endl;
    }

    void getLength()
    {
        cout << "Length: " << length << endl;
    }
    ~LinkedList()
    {
        Node *temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }
    void append(int value)
    {
        Node *newNode = new Node(value);
        if (length == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    /*
    void deleteLast(){
         if(length == 0) return;
         Node* temp = head;
         Node* pre = head;

         while(temp->next){
             pre = temp;
             temp = temp->next;
         }
         tail  = pre;
         tail -> next = nullptr;
         length--;
         if(length == 0){
             head = nullptr;
             tail = nullptr;
         }
         delete temp;
     }
    */

    void deleteLast()
    {
        if (length == 0)
            return;
        Node *temp = head;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node *pre = head;
            while (temp->next)
            {
                pre = temp;
                temp = temp->next;
            }
            tail = pre;
            tail->next = nullptr;
        }
        delete temp;
        length--;
    }

    void deleteFirst(){
        if(length == 0) return;
        Node* temp= head;

        if(length ==1){
            head = nullptr;
            tail = nullptr;
        }
        else{
            head = head->next;
        }
        delete temp;
        length--; 
    }

    Node* get(int index) {
        if(index < 0 || index>=length){
            return nullptr;
        }
        Node* temp = head;
        for(int i = 0; i<index; i++){
            temp = temp->next;
        }
        return temp;
    }

    bool set(int index, int value){
        Node* temp = get(index);
        if(temp){
            temp->value = value;
            return true;
        }
        return false;

    }

  bool insert(int index, int value){
    if(index < 0 || index > length) return false;
    if(index == 0) {
      append(value);
      return true;
    }
    if(index == length){
      append(value);
      return true;
    }

    Node* newNode = new Node(value);
    Node* temp = get(index - 1 );
    newNode->next = temp->next;
    temp->next = newNode;
    length++;
    return true;
  }

  void deleteNode(int index){
    if(index < 0 || index >= length) return;
    if(index == 0) return deleteFirst();
    if(index == length-1) return deleteLast();

    Node* prev = get(index -1);
    Node* temp = prev->next;

    prev->next = temp->next;
    delete temp;
    length--;

  }

  void reverse(){
    Node* temp = head;
    head = tail;
    tail = temp;
    Node* after = temp->next;
    Node* before = nullptr;

    for(int i = 0; i<length; i++) {
      after = temp->next;
      temp->next = before;
      before = temp;
      temp = after;
    }
  }
};

int main()
{
    LinkedList *mylinkedList = new LinkedList(4);
    mylinkedList->getHead();
    mylinkedList->getTail();
    mylinkedList->getLength();
    mylinkedList->append(1);
    mylinkedList->append(3);
    mylinkedList->printList();
    mylinkedList->deleteFirst();
    mylinkedList->printList(); cout << mylinkedList->get(1)->value;
    mylinkedList->set(2,4);
    mylinkedList->printList();
    mylinkedList->insert(1, 2);
}
