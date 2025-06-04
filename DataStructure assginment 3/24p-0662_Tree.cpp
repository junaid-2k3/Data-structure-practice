#include <iostream>
#include <queue>
using namespace std;

// Node structure for Binary Tree
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

    // Helper function to count divisor nodes
    int divisorNodesCounter(TreeNode* node, int rootValue) {
        if (!node) return 0;
        int count = (rootValue % node->data == 0) ? 1 : 0;
        int countleft = divisorNodesCounter(node->left, rootValue);
        int countright = divisorNodesCounter(node->right, rootValue);
        return countleft + countright + count;
    }

    //Helper function to check strictly binary tree
    bool isStrictlyBinaryHelper(TreeNode* node) {
        if (!node) return true;
        if (!node->left && !node->right) return true; // leaf node 
        if (node->left && node->right) {
            return isStrictlyBinaryHelper(node->left) && isStrictlyBinaryHelper(node->right);
        }
        return false;
    }

    // Helper function to count nodes at given height
    int countNodesAtHeightHelper(TreeNode* node, int currentHeight, int targetHeight) {
        if (!node) return 0;
        if (currentHeight == targetHeight) return 1;
        return countNodesAtHeightHelper(node->left, currentHeight + 1, targetHeight) +
               countNodesAtHeightHelper(node->right, currentHeight + 1, targetHeight);
    }

    // Helper function to find predecessor and successor
    void findPredecessorSuccessorHelper(TreeNode* node, int value, TreeNode*& predecessor, TreeNode*& successor) {
        if (!node) return;
        
        if (node->data == value) {
            if (node->left) {
                TreeNode* temp = node->left;
                while (temp->right) {
                    temp = temp->right;
                }
                predecessor = temp;
            }
            if (node->right) {
                TreeNode* temp = node->right;
                while (temp->left) {
                    temp = temp->left;
                }
                successor = temp;
            }
            return;
        }
        
        if (node->data > value) {
            successor = node;
            findPredecessorSuccessorHelper(node->left, value, predecessor, successor);
        } else {
            predecessor = node;
            findPredecessorSuccessorHelper(node->right, value, predecessor, successor);
        }
    }

    // Helper function to find lowest value in right subtree
    int findLowestInRightSubtreeHelper(TreeNode* node) {
        
    TreeNode* temp = node->right;
    while (temp->left != nullptr) {
        temp = temp->left;
    }

    return temp->data;
}

    // Helper function to find kth smallest element
    void kthSmallestHelper(TreeNode* node, int& k, int& result) {
        if (!node || k <= 0) return;
        
        kthSmallestHelper(node->left, k, result);
        k--;
        if (k == 0) {
            result = node->data;
            return;
        }
        kthSmallestHelper(node->right, k, result);
    }

public:
    BinaryTree() : root(nullptr) {}

    // Function to insert in BST
    void insert(int value) {
        TreeNode* newNode = new TreeNode(value);
        if (!root) {
            root = newNode;
            return;
        }
        
        TreeNode* current = root;
        TreeNode* parent = nullptr;
        
        while (current) {
            parent = current;
            if (value < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        
        if (value < parent->data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }

    // Function to count divisor nodes
    int countDivisorNodes() {  // public wrapper function
        if (!root) return 0;
        return divisorNodesCounter(root, root->data);
    }

    // Function to check strictly binary tree
    bool isStrictlyBinary() {
        return isStrictlyBinaryHelper(root);
    }

    // Function to count nodes at given height
    int countNodesAtHeight(int height) {
        return countNodesAtHeightHelper(root, 0, height);
    }

    // Function to find predecessor and successor
    void findPredecessorSuccessor(int value, int& predecessor, int& successor) {
        TreeNode* pred = nullptr;
        TreeNode* succ = nullptr;
        findPredecessorSuccessorHelper(root, value, pred, succ);
        predecessor = pred ? pred->data : -1;
        successor = succ ? succ->data : -1;
    }

    // Function to find lowest value in right subtree
    int findLowestInRightSubtree() {
        if (!root || !root->right) return -1;
        return findLowestInRightSubtreeHelper(root->right);
    }

    // Function to perform level order traversal
    void levelOrderTraversal() {
        if (!root) return;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode* current = q.front();
                q.pop();
                cout << current->data << " ";
                
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }
            cout << endl;
        }
    }

    // Function to find kth smallest element
    int kthSmallest(int k) {
        int result = -1;
        kthSmallestHelper(root, k, result);
        return result;
    }
};

int main() {
    BinaryTree tree;
    int choice, value, k, height;
    
    do {
        cout << "\n===== TREE OPERATIONS MENU =====" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Count Divisor Nodes" << endl;
        cout << "3. Check Strictly Binary Tree" << endl;
        cout << "4. Count Nodes at Given Height" << endl;
        cout << "5. Find Predecessor and Successor" << endl;
        cout << "6. Find Lowest Value in Right Subtree" << endl;
        cout << "7. Level Order Traversal" << endl;
        cout << "8. Find Kth Smallest Element" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            }
            case 2: {
                int count = tree.countDivisorNodes();
                cout << "Number of divisor nodes: " << count << endl;
                break;
            }
            case 3: {
                if (tree.isStrictlyBinary()) {
                    cout << "Tree is strictly binary!" << endl;
                } else {
                    cout << "Tree is not strictly binary!" << endl;
                }
                break;
            }
            case 4: {
                cout << "Enter height: ";
                cin >> height;
                int count = tree.countNodesAtHeight(height);
                cout << "Number of nodes at height " << height << ": " << count << endl;
                break;
            }
            case 5: {
                cout << "Enter value: ";
                cin >> value;
                int predecessor, successor;
                tree.findPredecessorSuccessor(value, predecessor, successor);
                cout << "Predecessor: " << predecessor << endl;
                cout << "Successor: " << successor << endl;
                break;
            }
            case 6: {
                int lowest = tree.findLowestInRightSubtree();
                if (lowest != -1) {
                    cout << "Lowest value in right subtree: " << lowest << endl;
                } else {
                    cout << "No right subtree exists!" << endl;
                }
                break;
            }
            case 7: {
                cout << "Level Order Traversal:" << endl;
                tree.levelOrderTraversal();
                break;
            }
            case 8: {
                cout << "Enter k: ";
                cin >> k;
                int result = tree.kthSmallest(k);
                if (result != -1) {
                    cout << k << "th smallest element: " << result << endl;
                } else {
                    cout << "Invalid k value!" << endl;
                }
                break;
            }
            case 9: {
                cout << "Exiting..." << endl;
                break;
            }
            default: {
                cout << "Invalid choice!" << endl;
            }
        }
    } while (choice != 9);
    
    return 0;
} 