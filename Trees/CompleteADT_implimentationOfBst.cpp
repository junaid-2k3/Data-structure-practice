// complete bst adt implimentation
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <queue>
using namespace std;
const int INSERT=1;const int DELETE=2;const int SEARCH=3;const int MINIMUM=4;const int MAXIMUM=5;
const int INORDER=6;const int PREORDER=7;const int POSTORDER=8;const int DISPLAY=9;const int TREE_HEIGHT=10;
const int COUNT_NODES=11; const int NODE_HEIGHT=12; const int NODE_DEPTH = 13; const int COUNT_NODES_AT_LEVEL = 14;
const int FIND_PARENT = 15; const int FIND_LEFT_CHILD = 16;const int FIND_RIGHT_CHILD = 17;
const int BREADTH_FIRST_SEARCH = 18;
const int EXIT=19;
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};
class BST {
private:
    Node* root;
    Node* insert(Node* root, int value) {
        if (root == nullptr) return new Node(value);
        if (value < root->data)
            root->left = insert(root->left, value);
        else
            root->right = insert(root->right, value);
        return root;
    }
    
    Node* deleteNode(Node* root, int key) {
        if (root == nullptr) return root;
        if (key < root->data)
            root->left = deleteNode(root->left, key);
        else if (key > root->data)
            root->right = deleteNode(root->right, key);
        else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }
    Node* findMin(Node* root) {
        while (root && root->left != nullptr)
            root = root->left;
        return root;
    }
    Node* findMax(Node* root) {
        while (root && root->right != nullptr)
            root = root->right;
        return root;
    }
    bool search(Node* root, int key) {
        if (root == nullptr) return false;
        if (key == root->data) return true;
        if (key < root->data)
            return search(root->left, key);
        else
            return search(root->right, key);
    }
    void inorder(Node* root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }
    void preorder(Node* root) {
        if (root != nullptr) {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }
    void postorder(Node* root) {
        if (root != nullptr) {
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
    }
    void destroyTree(Node* root) {// kind of a post order deletoion ;
        if (root != nullptr) {
            destroyTree(root->left);
            destroyTree(root->right);
            delete root;
        }
    }
    void display(Node* root, int space) {
        const int INDENT = 6;
        if (root == nullptr) return;
        display(root->right, space + INDENT);
        cout << setw(space) << ' ' << root->data << endl;
        display(root->left, space + INDENT);
    }
    int findHeight(Node *root) {              // calculate the height of a tree
    if (root == nullptr)
        return -1;
    else {
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);
        return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
        }
    }
    int countNodes(Node* root) {
    if (root == nullptr) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
    }
    Node* findNode(Node* root, int key) {
    if (root == nullptr || root->data == key) return root;
    if (key < root->data)
        return findNode(root->left, key);
    else
        return findNode(root->right, key);
    }
    int NodeHeight(Node* node) {
    if (node == nullptr) return -1;
    int leftHeight = findHeight(node->left);
    int rightHeight = findHeight(node->right);
    return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
    }

    int NodeDepth(Node* root, int key, int depth = 0) {
    if (root == nullptr) return -1; // Key not found
    if (root->data == key) return depth;
    if (key < root->data)
        return NodeDepth(root->left, key, depth + 1);
    else
        return NodeDepth(root->right, key, depth + 1);
   }

   int countNodesAtLevel(Node* node, int level) { //////////////////////////////////////?????
    if (node == nullptr)
        return 0;
    if (level == 0) // at level zero their is only one node and that is the root node
        return 1;
    return countNodesAtLevel(node->left, level - 1) +
           countNodesAtLevel(node->right, level - 1);
    }

    Node* findParent(Node* node, int value) {  ////////////////////////////////////??????
    if (node == nullptr || node->data == value)
        return nullptr;

    if ((node->left && node->left->data == value) ||
        (node->right && node->right->data == value))
        return node;

    if (value < node->data)
        return findParent(node->left, value);
    else
        return findParent(node->right, value);
    }
public:
    BST() : root(nullptr) {}
    ~BST() {
        destroyTree(root);
    }
    void insert(int value) {
        root = insert(root, value);
    }
    void deleteValue(int key) {
        root = deleteNode(root, key);
    }
    bool search(int key) {
        return search(root, key);
    }
    int findMin() {
        Node* temp = findMin(root);
        return temp ? temp->data : -1;
    }
    int findMax() {
        Node* temp = findMax(root);
        return temp ? temp->data : -1;
    }
    void inorderTraversal() {
        cout << "Inorder: ";
        inorder(root);
        cout << endl;
    }
    void preorderTraversal() {
        cout << "Preorder: ";
        preorder(root);
        cout << endl;
    }
    void postorderTraversal() {
        cout << "Postorder: ";
        postorder(root);
        cout << endl;
    }
    void display() {
        cout << "\nTree structure (root at left, right at top):\n";
        display(root, 0);
    }
    int findHeight() {
     return findHeight(root);
    }
    int countNodes() {
    return countNodes(root);
    }
    int NodeHeight(int value) {
    Node* node = findNode(root, value);
    if (!node) {
        cout << "Node not found in tree.\n";
        return -1;
    }
        return NodeHeight(node);
    }
    int NodeDepth(int key) {
        return NodeDepth(root, key);
    }
    int countNodesAtLevel(int level) {
        return countNodesAtLevel(root, level);
    }
    Node* findParent(int value) {
        return findParent(root, value);
    }
    int getLeftChild(int value) {
    Node* node = findNode(root, value);
    if (node && node->left)
        return node->left->data;
    else {
        cout << "Left child not found for node " << value << ".\n";
        return -1;
    }
    }
    int getRightChild(int value) {
    Node* node = findNode(root, value);
    if (node && node->right)
        return node->right->data;
    else {
        cout << "Right child not found for node " << value << ".\n";
        return -1;
    }
    }
    void breadthFirstTraversal() {
    if (root == nullptr) {
        cout << "Tree is empty.\n";
        return;
    }
    queue<Node*> q;
    q.push(root);
    cout << "BFS (Level Order): ";
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    cout << endl;
    }
    static void test(){cout<<"\n this is static function \n";}
};
int main() {
    BST tree;
    int choice, value, left_child, right_child;
    do {
        cout << "\n====== BST Operations Menu ======" << endl
        << "1.  Insert\n"
        << "2.  Delete\n"
        << "3.  Search\n"
        << "4.  Find Minimum\n"
        << "5.  Find Maximum\n"
        << "6.  Inorder Traversal\n"
        << "7.  Preorder Traversal\n"
        << "8.  Postorder Traversal\n"
        << "9.  Display Tree Structure\n"
        << "10. Height Of Tree Structure\n"
        << "11. Count Nodes in  Tree Structure\n"
        << "12. Find Height of a Node\n"
        << "13. Find Depth of a Node\n"
        << "14. Count Nodes at a Given Level\n"
        << "15. Find Parent of a Node\n"
        << "16. Find Left Child of a Node\n"
        << "17. Find Right Child of a Node\n"
        << "18. Breadth First Search (Traversal) \n"
        << "19. Exit\n"
        << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case INSERT:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case DELETE:
                cout << "Enter value to delete: ";
                cin >> value;
                tree.test();
                tree.deleteValue(value);
                break;
            case SEARCH:
                cout << "Enter value to search: ";
                cin >> value;
                if (tree.search(value))
                    cout << "Value found in tree.\n";
                else
                    cout << "Value not found.\n";
                break;
            case MINIMUM:
                value = tree.findMin();
                if (value != -1)
                    cout << "Minimum value: " << value << endl;
                else
                    cout << "Tree is empty.\n";
                break;
            case MAXIMUM:
                value = tree.findMax();
                if (value != -1)
                    cout << "Maximum value: " << value << endl;
                else
                    cout << "Tree is empty.\n";
                break;
            case INORDER:
                tree.inorderTraversal();
                break;
            case PREORDER:
                tree.preorderTraversal();
                break;
            case POSTORDER:
                tree.postorderTraversal();
                break;
            case DISPLAY:
                tree.display();
                break;
            case TREE_HEIGHT:
                cout<<"\n height of the tree is: "<<tree.findHeight();
                break;
            case EXIT:
                cout << "Exiting program. Thank you!\n";
                break;
            case COUNT_NODES:
                cout<<"\ntotal number of nodes in the tree = "<<tree.countNodes();
                break;
            case NODE_HEIGHT:
                cout << "Enter node value to find its height: ";  cin >> value;
                cout << "Height of node " << value << " is: " << tree.NodeHeight(value) << endl;
                break;
            case NODE_DEPTH:
                cout << "Enter node value to find depth: ";    cin >> value;
                {
                    int depth = tree.NodeDepth(value);
                    if (depth != -1)
                        cout << "Depth of node " << value << ": " << depth << endl;
                    else
                        cout << "Node not found.\n";
                }
                break;
            case COUNT_NODES_AT_LEVEL:
                cout << "Enter level to count nodes at: ";    cin >> value;
                cout << "Number of nodes at level " << value << ": "
                     << tree.countNodesAtLevel(value) << endl;
                break;
            case FIND_PARENT:
                cout << "Enter value to find its parent: ";  cin >> value;
                {
                    Node* parent = tree.findParent(value);
                if (parent)
                    cout << "Parent of " << value << " is: " << parent->data << endl;
                else
                    cout << "No parent found (node may be root or not exist).\n";
                }
                break;
            case FIND_LEFT_CHILD:
                cout << "Enter node value to find its left child: ";    cin >> value;
                left_child = tree.getLeftChild(value);
                if (left_child != -1 ) cout<<"\n left child = "<<left_child;
            break;
            case FIND_RIGHT_CHILD:
                cout << "Enter node value to find its right child: ";    cin >> value;
                right_child = tree.getRightChild(value);
                if (right_child != -1 ) cout<<"\n right child = "<<right_child;
                break;
            case BREADTH_FIRST_SEARCH:
                 tree.breadthFirstTraversal();
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
        if (choice != EXIT){ cout<<"\n press any key to continue"; _getch(); system("cls");}
    } while (choice != EXIT);

    return 0;
}
