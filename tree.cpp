#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* right;
    Node* left;
    
    Node(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() {
        root = nullptr;
    }

    bool Insert(int value) {
        Node* newNode = new Node(value);
        if (root == nullptr) {
            root = newNode;
            return true;
        }
        Node* temp = root;
        while (true) {
            if (newNode->value == temp->value) return false; // Duplicate values not allowed
            if (newNode->value < temp->value) {
                if (temp->left == nullptr) {
                    temp->left = newNode;
                    return true;
                }
                temp = temp->left;
            } else {
                if (temp->right == nullptr) {
                    temp->right = newNode;
                    return true;
                }
                temp = temp->right;
            }
        }
    }

    bool Contains(int value) {
        Node* temp = root;
        while (temp) {
            if (value < temp->value) {
                temp = temp->left;
            } else if (value > temp->value) {
                temp = temp->right;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    BinarySearchTree* myBST = new BinarySearchTree();

    // Inserting values into the BST
    myBST->Insert(10);
    myBST->Insert(5);
    myBST->Insert(15);
    myBST->Insert(2);
    myBST->Insert(5);  // Duplicate entry, should return false
    myBST->Insert(13);
    myBST->Insert(22);
    myBST->Insert(1);
    
    // Checking if values are contained within the BST
    cout << "Contains 10: " << (myBST->Contains(10) ? "Yes" : "No") << endl;
    cout << "Contains 15: " << (myBST->Contains(15) ? "Yes" : "No") << endl;
    cout << "Contains 99: " << (myBST->Contains(99) ? "Yes" : "No") << endl;

    // Cleanup
    delete myBST;
    return 0;
}
