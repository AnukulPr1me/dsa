#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;
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

    void insert(int value) {
        Node* newNode = new Node(value);
        if (root == nullptr) {
            root = newNode;
            return;
        }
        Node* temp = root;
        while (true) {
            if (value == temp->value) return; // Prevent duplicate insertion
            if (value < temp->value) { // Go left
                if (temp->left == nullptr) {
                    temp->left = newNode;
                    return;
                }
                temp = temp->left;
            } else { // Go right
                if (temp->right == nullptr) {
                    temp->right = newNode;
                    return;
                }
                temp = temp->right;
            }
        }
    }

    bool contains(int value) {
        if (root == nullptr) return false;
        Node* temp = root;
        while (temp != nullptr) {
            if (value < temp->value) {
                temp = temp->left;
            } else if (value > temp->value) {
                temp = temp->right;
            } else {
                return true; // Value found
            }
        }
        return false;
    }

    void BFS() {
        if (root == nullptr) return; // Handle empty tree
        queue<Node*> myQueue;
        myQueue.push(root);

        while (!myQueue.empty()) {
            Node* currentNode = myQueue.front();
            myQueue.pop();
            cout << currentNode->value << " "; // Print value, not address
            if (currentNode->left != nullptr) {
                myQueue.push(currentNode->left);
            }
            if (currentNode->right != nullptr) {
                myQueue.push(currentNode->right);
            }
        }
        cout << endl;
    }

    void preOrderDFS(Node* currentNode){
        cout << currentNode->value << " ";
        if(currentNode->left != nullptr){
            preOrderDFS(currentNode->left);
        }
        if(currentNode->right != nullptr){
            preOrderDFS(currentNode->right);
        }
    }
    void preOrderDFS() {preOrderDFS(root);}
    
    void postOrderDFS(Node* currentNode){
        if(currentNode->left != nullptr){
            postOrderDFS(currentNode->left);
        }
        if(currentNode->right != nullptr){
            postOrderDFS(currentNode->right);
        }
        cout << currentNode->value << " ";
    }
    void postOrderDFS() {postOrderDFS(root);}

    void inOrderDFS(Node* currentNode){
        if(currentNode->left != nullptr){
            inOrderDFS(currentNode->left);
        }
        cout << currentNode->value << " ";
        if(currentNode->right != nullptr){
            inOrderDFS(currentNode->right);
        }
    }
    void inOrderDFS() {inOrderDFS(root);}
};

int main() {
    BinarySearchTree myBST;

    myBST.insert(47);
    myBST.insert(21);
    myBST.insert(76);
    myBST.insert(18);
    myBST.insert(27);
    myBST.insert(52);
    myBST.insert(82);

    cout << "Breadth-First Search (BFS): ";
    myBST.BFS();
    cout << endl;
    myBST.postOrderDFS();
    cout << endl;
    myBST.preOrderDFS();
    cout << endl;
    myBST.inOrderDFS();
    cout << endl;

    

    // Testing `contains` method
    cout << "Contains 27? " << (myBST.contains(27) ? "Yes" : "No") << endl;
    cout << "Contains 100? " << (myBST.contains(100) ? "Yes" : "No") << endl;

    return 0;
}
