#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// BST Class
class BST {
private:
    Node* root;

    // Private helper functions
    Node* insert(Node* root, int val) {
        if (root == nullptr) return new Node(val);
        if (val < root->data) root->left = insert(root->left, val);
        else if (val > root->data) root->right = insert(root->right, val);
        // If value already exists, we don't insert duplicate
        return root;
    }

    Node* search(Node* root, int target) {
        if (root == nullptr || root->data == target) return root;
        
        if (target < root->data)
            return search(root->left, target);
        else
            return search(root->right, target);
    }

    Node* findMin(Node* root) {
        if (root == nullptr) return nullptr;
        while (root->left != nullptr)
            root = root->left;
        return root;
    }
   

    Node* deleteNode(Node* root, int key) {
        // Base case: empty tree
        if (root == nullptr) return root;

        // Navigate to the node to delete
        if (key < root->data)
            root->left = deleteNode(root->left, key);
        else if (key > root->data)
            root->right = deleteNode(root->right, key);
        else {
            // Node with only one child or no child
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = findMin(root->right);
            
            // Copy the inorder successor's data to this node
            root->data = temp->data;
            
            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    void inorder(Node* root) {
        if (root == nullptr) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void preorder(Node* root) {
        if (root == nullptr) return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node* root) {
        if (root == nullptr) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    int countNodes(Node* root) {
        if (root == nullptr) return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }

    int height(Node* root) {
        if (root == nullptr) return -1;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(Node* root) {
        if (root == nullptr) return true;
        
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        
        // Check if the current node is balanced and its subtrees are balanced
        return (abs(leftHeight - rightHeight) <= 1) && 
               isBalanced(root->left) && 
               isBalanced(root->right);
    }
    
    Node* clear(Node* root) {
        if (root == nullptr) return nullptr;
        
        // Recursively delete left and right subtrees
        root->left = clear(root->left);
        root->right = clear(root->right);
        
        // Delete current node
        delete root;
        return nullptr;
    }
    
    void printLevel(Node* root, int level) {
        if (root == nullptr) return;
        if (level == 0) {
            cout << root->data << " ";
        } else {
            printLevel(root->left, level - 1);
            printLevel(root->right, level - 1);
        }
    }

public:
    BST() { root = nullptr; }
    ~BST() { root = clear(root); }

    // Public interface functions
    void insert(int val) {
        root = insert(root, val);
    }

    bool search(int target) {
        return search(root, target) != nullptr;
    }

    void remove(int key) {
        root = deleteNode(root, key);
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }

    void preorder() {
        preorder(root);
        cout << endl;
    }

    void postorder() {
        postorder(root);
        cout << endl;
    }

    int countNodes() {
        return countNodes(root);
    }

    int height() {
        return height(root);
    }

    bool isBalanced() {
        return isBalanced(root);
    }
    
    bool isEmpty() {
        return root == nullptr;
    }
    
    void clear() {
        root = clear(root);
    }
    
    void levelOrderTraversal() {
        int h = height();
        for (int i = 0; i <= h; i++) {
            printLevel(root, i);
            cout << endl;
        }
    }
    
    // Find the minimum value in the tree
    int findMin() {
        if (isEmpty()) throw runtime_error("Tree is empty");
        Node* minNode = findMin(root);
        return minNode->data;
    }
    
    // Find the maximum value in the tree
    int findMax() {
        if (isEmpty()) throw runtime_error("Tree is empty");
        Node* current = root;
        while (current->right != nullptr) {
            current = current->right;
        }
        return current->data;
    }
};

int main() {
    BST tree;
    
    // Insert elements
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder Traversal: ";
    tree.inorder();  // Should print: 20 30 40 50 60 70 80

    cout << "Preorder Traversal: ";
    tree.preorder();  // Should print: 50 30 20 40 70 60 80

    cout << "Postorder Traversal: ";
    tree.postorder();  // Should print: 20 40 30 60 80 70 50

    cout << "Level Order Traversal: " << endl;
    tree.levelOrderTraversal();

    cout << "Number of nodes: " << tree.countNodes() << endl;  // Should print: 7
    cout << "Height of tree: " << tree.height() << endl;  // Should print: 2
    cout << "Tree is balanced: " << (tree.isBalanced() ? "Yes" : "No") << endl;  // Should print: Yes
    
    cout << "Min value: " << tree.findMin() << endl;  // Should print: 20
    cout << "Max value: " << tree.findMax() << endl;  // Should print: 80

    cout << "Search for 40: " << (tree.search(40) ? "Found" : "Not Found") << endl;  // Should print: Found
    cout << "Search for 55: " << (tree.search(55) ? "Found" : "Not Found") << endl;  // Should print: Not Found

    cout << "Removing 20..." << endl;
    tree.remove(20);
    cout << "Inorder after removal: ";
    tree.inorder();  // Should print: 30 40 50 60 70 80

    cout << "Removing 30..." << endl;
    tree.remove(30);
    cout << "Inorder after removal: ";
    tree.inorder();  // Should print: 40 50 60 70 80

    cout << "Removing 50 (root)..." << endl;
    tree.remove(50);
    cout << "Inorder after removal: ";
    tree.inorder();  // Should print: 40 60 70 80

    cout << "Clearing the tree..." << endl;
    tree.clear();
    cout << "Tree is empty: " << (tree.isEmpty() ? "Yes" : "No") << endl;  // Should print: Yes

    return 0;
}