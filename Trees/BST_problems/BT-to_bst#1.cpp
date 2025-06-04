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

// Step 1: Extract values using inorder traversal
void extractvalues(Node* root, vector<int>& treeVec) {
    if (!root) return;
    extractvalues(root->left, treeVec);
    treeVec.push_back(root->data);
    extractvalues(root->right, treeVec);
}

// Step 2: Replace node values using inorder traversal with sorted values
void replaceWithSorted(Node* root, vector<int>& treeVec, int& index) {
    if (!root) return;
    replaceWithSorted(root->left, treeVec, index);
    root->data = treeVec[index++];
    replaceWithSorted(root->right, treeVec, index);
}

// Utility function to print inorder traversal
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    // Original binary tree
    Node* root = new Node(24);
    root->left = new Node(15);
    root->right = new Node(4);
    root->left->left = new Node(2);
    root->left->right = new Node(22);
    root->left->right->left = new Node(12);
    root->right->left = new Node(6);
    root->right->right = new Node(10);

    // Step 1: Extract all values from tree
    vector<int> treeVector;
    extractvalues(root, treeVector);

    // Step 2: Sort the values
    sort(treeVector.begin(), treeVector.end());

    // Step 3: Replace values in the original tree using sorted values
    int index = 0;
    replaceWithSorted(root, treeVector, index);

    // Final: Print the inorder traversal (should be sorted)
    cout << "Inorder traversal of converted BST: ";
    inorder(root);
    cout << endl;

    return 0;
}
