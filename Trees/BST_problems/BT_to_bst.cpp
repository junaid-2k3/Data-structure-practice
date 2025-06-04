#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Step 1: Extract values from the original binary tree (inorder traversal)
void extractvalues(Node* root, vector<int>& treeVec) {
    if (!root) return;
    extractvalues(root->left, treeVec);
    treeVec.push_back(root->data);
    extractvalues(root->right, treeVec);
}

// Step 2: Insert values into BST (standard BST insertion)
Node* insertInBST(Node* root, int val) {
    if (root == nullptr) return new Node(val);
    if (val < root->data)
        root->left = insertInBST(root->left, val);
    else if (val > root->data)
        root->right = insertInBST(root->right, val);
    return root;
}

// Utility function for inorder traversal
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    // Original binary tree (not necessarily BST)
    Node* root = new Node(24);
    root->left = new Node(15);
    root->right = new Node(4);
    root->left->left = new Node(2);
    root->left->right = new Node(22);
    root->left->right->left = new Node(12);
    root->right->left = new Node(6);
    root->right->right = new Node(10);

    // Step 1: Extract values from the binary tree
    vector<int> treeVec;
    extractvalues(root, treeVec);

    // Step 2: Sort the values
    // sort(treeVec.begin(), treeVec.end());

    // Step 3: Build the BST using the sorted values
    Node* BstRoot = nullptr;
    for (int val : treeVec) {
        BstRoot = insertInBST(BstRoot, val);
    }

    // Step 4: Print inorder traversal of the new BST
    cout << "Inorder traversal of BST: ";
    inorder(BstRoot);
    cout << endl;

    return 0;
}
