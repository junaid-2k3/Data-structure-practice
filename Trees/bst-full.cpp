#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <climits>
#include <algorithm>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Binary Search Tree class
class BST {
private:
    Node* root;
    
    // -------------- PRIVATE HELPER METHODS ------------------
    
    // 1. Basic Operations
    Node* insertHelper(Node* root, int val) {
        if (root == nullptr) return new Node(val);
        
        if (val < root->data) 
            root->left = insertHelper(root->left, val);
        else if (val > root->data) 
            root->right = insertHelper(root->right, val);
        
        return root;
    }
    
    Node* findMin(Node* root) {
        if (root == nullptr) return nullptr;
        while (root->left != nullptr)
            root = root->left;
        return root;
    }
    
    Node* findMax(Node* root) {
        if (root == nullptr) return nullptr;
        while (root->right != nullptr)
            root = root->right;
        return root;
    }
    
    Node* deleteNodeHelper(Node* root, int key) {
        if (root == nullptr) return root;
        
        // Navigate to the node to delete
        if (key < root->data)
            root->left = deleteNodeHelper(root->left, key);
        else if (key > root->data)
            root->right = deleteNodeHelper(root->right, key);
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
            
            // Node with two children
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNodeHelper(root->right, temp->data);
        }
        return root;
    }
    
    Node* searchHelper(Node* root, int key) {
        if (root == nullptr || root->data == key)
            return root;
        
        if (key < root->data)
            return searchHelper(root->left, key);
        return searchHelper(root->right, key);
    }
    
    // 2. Traversal Techniques
    void inorderHelper(Node* root, vector<int>& result) {
        if (root == nullptr) return;
        inorderHelper(root->left, result);
        result.push_back(root->data);
        inorderHelper(root->right, result);
    }
    
    void preorderHelper(Node* root, vector<int>& result) {
        if (root == nullptr) return;
        result.push_back(root->data);
        preorderHelper(root->left, result);
        preorderHelper(root->right, result);
    }
    
    void postorderHelper(Node* root, vector<int>& result) {
        if (root == nullptr) return;
        postorderHelper(root->left, result);
        postorderHelper(root->right, result);
        result.push_back(root->data);
    }
    
    // 3. Finding Key Properties
    int heightHelper(Node* root) {
        if (root == nullptr) return -1;
        int leftHeight = heightHelper(root->left);
        int rightHeight = heightHelper(root->right);
        return max(leftHeight, rightHeight) + 1;
    }
    
    void kthSmallestHelper(Node* root, int& k, int& result) {
        if (root == nullptr) return;
        
        kthSmallestHelper(root->left, k, result);
        
        k--;
        if (k == 0) {
            result = root->data;
            return;
        }
        
        kthSmallestHelper(root->right, k, result);
    }
    
    void kthLargestHelper(Node* root, int& k, int& result) {
        if (root == nullptr) return;
        
        kthLargestHelper(root->right, k, result);
        
        k--;
        if (k == 0) {
            result = root->data;
            return;
        }
        
        kthLargestHelper(root->left, k, result);
    }
    
    // 4. Validation and Checking
    bool isBSTHelper(Node* root, int minVal, int maxVal) {
        if (root == nullptr) return true;
        
        if (root->data <= minVal || root->data >= maxVal)
            return false;
        
        return isBSTHelper(root->left, minVal, root->data) &&
               isBSTHelper(root->right, root->data, maxVal);
    }
    
    bool isBalancedHelper(Node* root, int& height) {
        if (root == nullptr) {
            height = -1;
            return true;
        }
        
        int leftHeight = 0, rightHeight = 0;
        bool leftBalanced = isBalancedHelper(root->left, leftHeight);
        bool rightBalanced = isBalancedHelper(root->right, rightHeight);
        
        height = max(leftHeight, rightHeight) + 1;
        
        if (!leftBalanced || !rightBalanced)
            return false;
        
        return abs(leftHeight - rightHeight) <= 1;
    }
    
    bool areIdenticalHelper(Node* root1, Node* root2) {
        if (root1 == nullptr && root2 == nullptr)
            return true;
        
        if (root1 == nullptr || root2 == nullptr)
            return false;
        
        return (root1->data == root2->data) &&
               areIdenticalHelper(root1->left, root2->left) &&
               areIdenticalHelper(root1->right, root2->right);
    }
    
    // 5. Range Queries
    void printRangeHelper(Node* root, int L, int R, vector<int>& result) {
        if (root == nullptr) return;
        
        if (root->data > L)
            printRangeHelper(root->left, L, R, result);
        
        if (root->data >= L && root->data <= R)
            result.push_back(root->data);
        
        if (root->data < R)
            printRangeHelper(root->right, L, R, result);
    }
    
    int countNodesInRangeHelper(Node* root, int L, int R) {
        if (root == nullptr) return 0;
        
        if (root->data >= L && root->data <= R)
            return 1 + countNodesInRangeHelper(root->left, L, R) +
                   countNodesInRangeHelper(root->right, L, R);
        
        if (root->data < L)
            return countNodesInRangeHelper(root->right, L, R);
            
        return countNodesInRangeHelper(root->left, L, R);
    }
    
    // 6. Modifications
    void bstToDllHelper(Node* root, Node*& prev, Node*& head) {
        if (root == nullptr) return;
        
        bstToDllHelper(root->left, prev, head);
        
        if (prev == nullptr) {
            head = root;
        } else {
            root->left = prev;
            prev->right = root;
        }
        
        prev = root;
        
        bstToDllHelper(root->right, prev, head);
    }
    
    void storeInorder(Node* root, vector<Node*>& nodes) {
        if (root == nullptr) return;
        storeInorder(root->left, nodes);
        nodes.push_back(root);
        storeInorder(root->right, nodes);
    }
    
    Node* buildBalancedBST(vector<Node*>& nodes, int start, int end) {
        if (start > end) return nullptr;
        
        int mid = (start + end) / 2;
        Node* root = nodes[mid];
        
        root->left = buildBalancedBST(nodes, start, mid - 1);
        root->right = buildBalancedBST(nodes, mid + 1, end);
        
        return root;
    }
    
    // 7. Successor and Predecessor
    Node* inorderSuccessor(Node* root, Node* p) {
        if (root == nullptr) return nullptr;
        
        Node* successor = nullptr;
        
        while (root != nullptr) {
            if (p->data < root->data) {
                successor = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        
        return successor;
    }
    
    Node* inorderPredecessor(Node* root, Node* p) {
        if (root == nullptr) return nullptr;
        
        Node* predecessor = nullptr;
        
        while (root != nullptr) {
            if (p->data > root->data) {
                predecessor = root;
                root = root->right;
            } else {
                root = root->left;
            }
        }
        
        return predecessor;
    }
    
    // 8. Advanced Applications
    Node* findLCAHelper(Node* root, int n1, int n2) {
        if (root == nullptr) return nullptr;
        
        if (root->data > n1 && root->data > n2)
            return findLCAHelper(root->left, n1, n2);
            
        if (root->data < n1 && root->data < n2)
            return findLCAHelper(root->right, n1, n2);
            
        return root;
    }
    
    Node* constructFromPreorderHelper(vector<int>& preorder, int& index, int min, int max) {
        if (index >= preorder.size()) return nullptr;
        
        int val = preorder[index];
        if (val < min || val > max) return nullptr;
        
        Node* root = new Node(val);
        index++;
        
        root->left = constructFromPreorderHelper(preorder, index, min, val - 1);
        root->right = constructFromPreorderHelper(preorder, index, val + 1, max);
        
        return root;
    }
    
    // Helper methods for merging two BSTs
    void inorderFill(Node* root, vector<int>& arr) {
        if (root == nullptr) return;
        inorderFill(root->left, arr);
        arr.push_back(root->data);
        inorderFill(root->right, arr);
    }
    
    Node* sortedArrayToBST(vector<int>& arr, int start, int end) {
        if (start > end) return nullptr;
        
        int mid = (start + end) / 2;
        Node* root = new Node(arr[mid]);
        
        root->left = sortedArrayToBST(arr, start, mid - 1);
        root->right = sortedArrayToBST(arr, mid + 1, end);
        
        return root;
    }
    
    // Helper for shortest path
    int shortestPathHelper(Node* root, int a, int b) {                
        Node* lca = findLCAHelper(root, a, b);
        
        // Calculate distance from LCA to node a
        int distA = distanceFromNode(lca, a, 0);
        
        // Calculate distance from LCA to node b
        int distB = distanceFromNode(lca, b, 0);
        
        return distA + distB;
    }
    
    int distanceFromNode(Node* root, int val, int distance) {
        if (root == nullptr) return -1;
        
        if (root->data == val) return distance;
        
        if (val < root->data) {
            int d = distanceFromNode(root->left, val, distance + 1);
            if (d != -1) return d;
        } else {
            int d = distanceFromNode(root->right, val, distance + 1);
            if (d != -1) return d;
        }
        
        return -1;
    }
    
    // 9. Miscellaneous Problems
    int largestBSTSubtreeHelper(Node* root, int& min_val, int& max_val, int& max_size, bool& is_bst) {
        if (root == nullptr) {
            is_bst = true;
            return 0;
        }
        
        int left_min = INT_MAX;
        int left_max = INT_MIN;
        int right_min = INT_MAX;
        int right_max = INT_MIN;
        int left_size = 0;
        int right_size = 0;
        bool left_is_bst = false;
        bool right_is_bst = false;
        
        left_size = largestBSTSubtreeHelper(root->left, left_min, left_max, max_size, left_is_bst);
        right_size = largestBSTSubtreeHelper(root->right, right_min, right_max, max_size, right_is_bst);
        
        min_val = min(root->data, left_min);
        max_val = max(root->data, right_max);
        
        if ((!root->left || (left_is_bst && left_max < root->data)) &&
            (!root->right || (right_is_bst && right_min > root->data))) {
            is_bst = true;
            int curr_size = left_size + right_size + 1;
            max_size = max(max_size, curr_size);
            return curr_size;
        }
        
        is_bst = false;
        return 0;
    }
    
    void recoverBSTHelper(Node* root, Node*& first, Node*& second, Node*& prev) {
        if (root == nullptr) return;
        
        recoverBSTHelper(root->left, first, second, prev);
        
        if (prev != nullptr && prev->data > root->data) {
            if (first == nullptr) {
                first = prev;
            }
            second = root;
        }
        
        prev = root;
        
        recoverBSTHelper(root->right, first, second, prev);
    }
    
    void countPairsHelper(Node* root1, Node* root2, int sum, int& count) {
        if (root1 == nullptr) return;
        
        countPairsHelper(root1->left, root2, sum, count);
        
        if (bstContains(root2, sum - root1->data)) {
            count++;
        }
        
        countPairsHelper(root1->right, root2, sum, count);
    }
    
    bool bstContains(Node* root, int key) {
        if (root == nullptr) return false;
        
        if (root->data == key) return true;
        
        if (key < root->data)
            return bstContains(root->left, key);
        else
            return bstContains(root->right, key);
    }
    
    // Helper method to delete the entire tree
    void clearTree(Node* root) {
        if (root == nullptr) return;
        clearTree(root->left);
        clearTree(root->right);
        delete root;
    }
    
public:
    BST() : root(nullptr) {}
    
    ~BST() {
        clearTree(root);
    }
    
    // -------------- PUBLIC INTERFACE METHODS ------------------
    
    // 1. Basic Operations
    void insert(int val) {
        root = insertHelper(root, val);
    }
    
    void remove(int key) {
        root = deleteNodeHelper(root, key);
    }
    
    bool search(int key) {
        return searchHelper(root, key) != nullptr;
    }
    
    // 2. Traversal Techniques
    vector<int> inorderTraversal() {
        vector<int> result;
        inorderHelper(root, result);
        return result;
    }
    
    vector<int> preorderTraversal() {
        vector<int> result;
        preorderHelper(root, result);
        return result;
    }
    
    vector<int> postorderTraversal() {
        vector<int> result;
        postorderHelper(root, result);
        return result;
    }
    
    vector<vector<int>> levelOrderTraversal() {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;
            
            for (int i = 0; i < levelSize; i++) {
                Node* node = q.front();
                q.pop();
                
                currentLevel.push_back(node->data);
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            result.push_back(currentLevel);
        }
        
        return result;
    }
    
    // 3. Finding Key Properties
    int findMinimum() {
        Node* minNode = findMin(root);
        if (minNode == nullptr) throw runtime_error("Tree is empty");
        return minNode->data;
    }
    
    int findMaximum() {
        Node* maxNode = findMax(root);
        if (maxNode == nullptr) throw runtime_error("Tree is empty");
        return maxNode->data;
    }
    
    int height() {
        return heightHelper(root);
    }
    
    int kthSmallest(int k) {
        if (k <= 0) throw runtime_error("k must be positive");
        
        int result = -1;
        kthSmallestHelper(root, k, result);
        
        if (result == -1) throw runtime_error("k is larger than tree size");
        return result;
    }
    
    int kthLargest(int k) {
        if (k <= 0) throw runtime_error("k must be positive");
        
        int result = -1;
        kthLargestHelper(root, k, result);
        
        if (result == -1) throw runtime_error("k is larger than tree size");
        return result;
    }
    
    // 4. Validation and Checking
    bool isBST() {
        return isBSTHelper(root, INT_MIN, INT_MAX);
    }
    
    bool isBalanced() {
        int height = 0;
        return isBalancedHelper(root, height);
    }
    
    bool areIdentical(BST& other) {
        return areIdenticalHelper(root, other.root);
    }
    
    // 5. Range Queries
    vector<int> printNodesInRange(int L, int R) {
        vector<int> result;
        printRangeHelper(root, L, R, result);
        return result;
    }
    
    int countNodesInRange(int L, int R) {
        return countNodesInRangeHelper(root, L, R);
    }
    
    // 6. Modifications
    Node* bstToDoublyLinkedList() {
        if (root == nullptr) return nullptr;
        
        Node* head = nullptr;
        Node* prev = nullptr;
        
        bstToDllHelper(root, prev, head);
        
        // Make it circular (optional)
        // head->left = prev;
        // prev->right = head;
        
        return head;
    }
    
    void balanceBST() {
        if (root == nullptr) return;
        
        vector<Node*> nodes;
        storeInorder(root, nodes);
        
        root = buildBalancedBST(nodes, 0, nodes.size() - 1);
    }
    
    // 7. Successor and Predecessor
    int findSuccessor(int key) {
        Node* node = searchHelper(root, key);
        if (node == nullptr) throw runtime_error("Key not found");
        
        Node* succ = inorderSuccessor(root, node);
        if (succ == nullptr) throw runtime_error("No successor found");
        
        return succ->data;
    }
    
    int findPredecessor(int key) {
        Node* node = searchHelper(root, key);
        if (node == nullptr) throw runtime_error("Key not found");
        
        Node* pred = inorderPredecessor(root, node);
        if (pred == nullptr) throw runtime_error("No predecessor found");
        
        return pred->data;
    }
    
    // 8. Advanced Applications
    int findLCA(int n1, int n2) {
        Node* lca = findLCAHelper(root, n1, n2);
        if (lca == nullptr) throw runtime_error("Nodes not found");
        return lca->data;
    }
    
    void constructFromPreorder(vector<int>& preorder) {
        clearTree(root);
        int index = 0;
        root = constructFromPreorderHelper(preorder, index, INT_MIN, INT_MAX);
    }
    
    void mergeBST(BST& other) {
        vector<int> arr1, arr2, merged;
        
        inorderFill(root, arr1);
        inorderFill(other.root, arr2);
        
        // Merge the two sorted arrays
        int i = 0, j = 0;
        
        while (i < arr1.size() && j < arr2.size()) {
            if (arr1[i] < arr2[j])
                merged.push_back(arr1[i++]);
            else
                merged.push_back(arr2[j++]);
        }
        
        while (i < arr1.size())
            merged.push_back(arr1[i++]);
            
        while (j < arr2.size())
            merged.push_back(arr2[j++]);
        
        // Clear current tree
        clearTree(root);
        
        // Build new balanced tree
        root = sortedArrayToBST(merged, 0, merged.size() - 1);
    }
    
    int shortestPath(int a, int b) {
        if (!search(a) || !search(b)) throw runtime_error("One or both nodes not found");
        return shortestPathHelper(root, a, b);
    }
    
    // 9. Miscellaneous Problems
    int largestBSTSubtree() {
        int min_val = INT_MAX;
        int max_val = INT_MIN;
        int max_size = 0;
        bool is_bst = false;
        
        largestBSTSubtreeHelper(root, min_val, max_val, max_size, is_bst);
        return max_size;
    }
    
    void recoverBST() {
        Node* first = nullptr;
        Node* second = nullptr;
        Node* prev = nullptr;
        
        recoverBSTHelper(root, first, second, prev);
        
        if (first && second) {
            // Swap the values
            int temp = first->data;
            first->data = second->data;
            second->data = temp;
        }
    }
    
    int countPairs(BST& other, int sum) {
        int count = 0;
        countPairsHelper(root, other.root, sum, count);
        return count;
    }
    
    // Additional utility methods
    void printInorder() {
        vector<int> result = inorderTraversal();
        for (int val : result) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    void printLevelOrder() {
        vector<vector<int>> levels = levelOrderTraversal();
        for (const auto& level : levels) {
            for (int val : level) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
    
    void printNodesInRangeOutput(int L, int R) {
        vector<int> result = printNodesInRange(L, R);
        for (int val : result) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    void printDLL(Node* head) {
        while (head != nullptr) {
            cout << head->data << " ";
            head = head->right;
        }
        cout << endl;
    }
};

int main() {
    BST tree;
    
    cout << "---------- BST OPERATIONS DEMO ----------\n\n";
    
    // 1. Basic Operations
    cout << "1. Basic Operations:\n";
    
    // Insert
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    
    cout << "  * Tree after insertions (inorder): ";
    tree.printInorder();
    
    // Search
    cout << "  * Search for 40: " << (tree.search(40) ? "Found" : "Not Found") << endl;
    cout << "  * Search for 90: " << (tree.search(90) ? "Found" : "Not Found") << endl;
    
    // Delete
    cout << "  * Deleting node 30..." << endl;
    tree.remove(30);
    cout << "  * Tree after deletion (inorder): ";
    tree.printInorder();
    
    // 2. Traversal Techniques
    cout << "\n2. Traversal Techniques:\n";
    
    // Reset tree
    tree = BST();
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    
    cout << "  * Inorder Traversal: ";
    tree.printInorder();
    
    cout << "  * Preorder Traversal: ";
    vector<int> preorder = tree.preorderTraversal();
    for (int val : preorder) cout << val << " ";
    cout << endl;
    
    cout << "  * Postorder Traversal: ";
    vector<int> postorder = tree.postorderTraversal();
    for (int val : postorder) cout << val << " ";
    cout << endl;
    
    cout << "  * Level-order Traversal: \n";
    tree.printLevelOrder();
    
    // 3. Finding Key Properties
    cout << "\n3. Finding Key Properties:\n";
    
    cout << "  * Minimum value: " << tree.findMinimum() << endl;
    cout << "  * Maximum value: " << tree.findMaximum() << endl;
    cout << "  * Height of the tree: " << tree.height() << endl;
    cout << "  * 3rd smallest element: " << tree.kthSmallest(3) << endl;
    cout << "  * 2nd largest element: " << tree.kthLargest(2) << endl;
    
    // 4. Validation and Checking
    cout << "\n4. Validation and Checking:\n";
    
    cout << "  * Is the tree a valid BST? " << (tree.isBST() ? "Yes" : "No") << endl;
    cout << "  * Is the tree balanced? " << (tree.isBalanced() ? "Yes" : "No") << endl;
    
    // Create another identical tree to test
    BST tree2;
    tree2.insert(50);
    tree2.insert(30);
    tree2.insert(70);
    tree2.insert(20);
    tree2.insert(40);
    tree2.insert(60);
    tree2.insert(80);
    
    cout << "  * Are the two trees identical? " << (tree.areIdentical(tree2) ? "Yes" : "No") << endl;
    
    // 5. Range Queries
    cout << "\n5. Range Queries:\n";
    
    cout << "  * Nodes in range [30, 70]: ";
    tree.printNodesInRangeOutput(30, 70);
    
    cout << "  * Count of nodes in range [30, 70]: " << tree.countNodesInRange(30, 70) << endl;
    
    // 6. Modifications
    cout << "\n6. Modifications:\n";
    
    cout << "  * Converting BST to Doubly LinkedList: ";
    Node* dll_head = tree.bstToDoublyLinkedList();
    tree.printDLL(dll_head);
    
    // Create a new tree with unbalanced structure
    BST unbalanced_tree;
    unbalanced_tree.insert(10);
    unbalanced_tree.insert(20);
    unbalanced_tree.insert(30);
    unbalanced_tree.insert(40);
    unbalanced_tree.insert(50);
    
    cout << "  * Unbalanced tree (inorder): ";
    unbalanced_tree.printInorder();
    cout << "    Height before balancing: " << unbalanced_tree.height() << endl;
    
    unbalanced_tree.balanceBST();
    
    cout << "  * After balancing (inorder): ";
    unbalanced_tree.printInorder();
    cout << "    Height after balancing: " << unbalanced_tree.height() << endl;
    
    // 7. Successor and Predecessor
    cout << "\n7. Successor and Predecessor:\n";
    
    // Reset tree
    tree = BST();
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    
    cout << "  * Inorder successor of 40: " << tree.findSuccessor(40) << endl;
    cout << "  * Inorder predecessor of 60: " << tree.findPredecessor(60) << endl;
    
    // 8. Advanced Applications
    cout << "\n8. Advanced Applications:\n";
    
    cout << "  * Lowest Common Ancestor of 20 and 40: " << tree.findLCA(20, 40) << endl;
    
    // Construct BST from preorder
    vector<int> pre_traversal = {50, 30, 20, 40, 70, 60, 80};
    BST preorder_tree;
    preorder_tree.constructFromPreorder(pre_traversal);
    
    cout << "  * Tree constructed from preorder (inorder): ";
    preorder_tree.printInorder();
    
    // Merge two BSTs
    BST tree3;
    tree3.insert(10);
    tree3.insert(5);
    tree3.insert(15);
    
    BST tree4;
    tree4.insert(7);
    tree4.insert(3);
    tree4.insert(12);
    
    cout << "  * First tree (inorder): ";
    tree3.printInorder();
    cout << "  * Second tree (inorder): ";
    tree4.printInorder();
    
    tree3.mergeBST(tree4);
    
    cout << "  * Merged tree (inorder): ";
    tree3.printInorder();
    // Continue with the main function from the previous code block
    cout << "  * Shortest path between nodes 20 and 80: " << tree.shortestPath(20, 80) << endl;

    // 9. Miscellaneous Problems
    cout << "\n9. Miscellaneous Problems:\n";

    // Create a binary tree (not necessarily a BST)
    BST non_bst;
    non_bst.insert(50);
    non_bst.root = new Node(50);  // Manually create to break BST property
    non_bst.root->left = new Node(30);
    non_bst.root->right = new Node(70);
    non_bst.root->left->left = new Node(20);
    non_bst.root->left->right = new Node(60);  // This violates BST property
    non_bst.root->right->left = new Node(10);  // This violates BST property
    non_bst.root->right->right = new Node(80);

    cout << "  * Size of largest BST subtree: " << non_bst.largestBSTSubtree() << endl;

    // Create a BST with two swapped nodes
    BST swapped_tree;
    swapped_tree.root = new Node(50);
    swapped_tree.root->left = new Node(70);  // Swapped with 30
    swapped_tree.root->right = new Node(30);  // Swapped with 70
    swapped_tree.root->left->left = new Node(20);
    swapped_tree.root->left->right = new Node(40);
    swapped_tree.root->right->left = new Node(60);
    swapped_tree.root->right->right = new Node(80);

    cout << "  * Swapped tree (inorder before recovery): ";
    swapped_tree.printInorder();

    swapped_tree.recoverBST();

    cout << "  * After recovery (inorder): ";
    swapped_tree.printInorder();

    // Count pairs with given sum
    BST tree5;
    tree5.insert(5);
    tree5.insert(3);
    tree5.insert(7);
    tree5.insert(2);
    tree5.insert(4);
    tree5.insert(6);
    tree5.insert(8);

    BST tree6;
    tree6.insert(10);
    tree6.insert(6);
    tree6.insert(15);
    tree6.insert(3);
    tree6.insert(8);
    tree6.insert(12);
    tree6.insert(18);

    int sum = 18;
    cout << "  * Count of pairs with sum " << sum << " (between two trees): " << tree5.countPairs(tree6, sum) << endl;

    cout << "\nAll operations completed successfully!" << endl;

    return 0;
}