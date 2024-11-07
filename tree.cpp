#include <iostream>

using namespace std;

class Node{
public:
    int value;
    Node* right;
    Node* left;
    
    Node(int value){
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree{
public:
    Node* root;
public:
    BinarySearchTree(){
        root = nullptr;
    }

    bool insert(int value){
        Node* newNode = new Node(value);
        if(root == nullptr){
            root = newNode;
            return true;
        }
        Node* temp = root;
        while(true){
            if(newNode->value == temp->value) return true;
            if(newNode->value < temp->value){
                if(temp->left == nullptr){
                    temp->left = newNode;
                    return true;
                }
                temp = temp->left;
            }else{
                if(temp->right == nullptr){
                    temp->right = newNode;
                    return true;
                }
                temp = temp->right;
            }
        }
    }
};

int main(){
    BinarySearchTree* myBST = new BinarySearchTree();
    cout << "bst: " << myBST->root << endl;
}