// find a node an print its path form the node to the root 
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

bool findPath(Node* root, int key, vector<int>& path) {
    if (!root) return false;

    // Add current node to path
    path.push_back(root->data);

    // Check if this is the key
    if (root->data == key) return true;

    // Recur to left or right
    if ((key < root->data && findPath(root->left, key, path)) ||
        (key > root->data && findPath(root->right, key, path))) {
        return true;
    }

    // If not found, remove the current node from path
    path.pop_back();
    return false;
}

int main() {
    // Example BST
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    int key = 60;
    vector<int> path;

    if (findPath(root, key, path)) {
        cout << "Path from root to " << key << ": ";
        for (int val : path)
            cout << val << " ";
        cout << endl;
    } else {
        cout << "Key not found in BST." << endl;
    }

    return 0;
}
