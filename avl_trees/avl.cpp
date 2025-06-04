// full implimenttaion of AVL tree 
#include<iostream>
#include<iomanip>
#include<conio.h>
#include<queue>

using namespace std;
// constants for menu 
const short int EXIT = 0,INSERTION = 1, DELETION = 2, DISPLAY =3 , DELETE_TREE=4, SEARCH=5, FIND_MINIMUM=6,
FIND_MAXIMUM=7, COUNT_NODES=8, FIND_DEPTH=9, COUNT_NODES_AT_LEVEL=10, FIND_PARENT=11, FIND_LEFT_CHILD=12,
FIND_RIGHT_CHILD=13, BREADTH_FIRST_TRAVERSAL = 14, DEPTH_FIRST_SEARCH_PRE = 15, DEPTH_FIRST_SEARCH_IN =16,
DEPTH_FIRST_SEARCH_POST =17;

class Node{
public:
    int key, height; // in aval tree it is essential to keep the height of every tree that is why we are keeping a variable named height
    Node *left,*right;
    Node(int value):key(value),height(0),left(nullptr),right(nullptr){} // every new node would have a height of zero ie :height(0)
};

class AVL{
private: // private section will have the core implementation of the funcitons and while we will call those function in the public wrappers defined in public sections
    Node *root; int value; // value for insertion and deletion etc
    //Inserting node in an AVL TREE
    Node* insertNode(Node *node, int key, bool& duplicate) {
    // If current node is null, insert the new node here
    if (!node)
        return new Node(key);  // Base case: found position, create new node

    // If key is less than current node's key, go left
    if (key < node->key)
        node->left = insertNode(node->left, key, duplicate);

    // If key is greater than current node's key, go right
    else if (key > node->key)
        node->right = insertNode(node->right, key, duplicate);

    // If key already exists, mark duplicate and return current node
    else {
        duplicate = true;  // Mark duplicate
        return node;       // Do not insert anything
    }

    // After insertion, balance the tree 
    node = balanceTree(node);

    // Return the (possibly balanced) subtree root
    return node;
}

// perform right rotation.
Node* rotateRight(Node *unbalancedNode){
    Node* elevatedBranchRoot = unbalancedNode->left; // elevate left branch;
    Node* rightSubTree = elevatedBranchRoot->right;  // save right sub-tree before rotation.
    elevatedBranchRoot->right = unbalancedNode;      // right rotate unbalanced node.
    unbalancedNode->left = rightSubTree;             // insert right sub-tree to the left of unbalanced node.
    updateHeight(unbalancedNode);                    // update height of unbalanced node first as it moved to lower level.
    updateHeight(elevatedBranchRoot);                // update height of elevated branch root second as it moved higher level.
    return elevatedBranchRoot;                       // return the new position of the elevated root.
}
// perform left rotation.
Node* rotateLeft(Node *unbalancedNode){
    Node *elevatedBranchRoot = unbalancedNode->right; // elevate right branch;
    Node *leftSubTree = elevatedBranchRoot->left;     // save left sub-tree before rotation.
    elevatedBranchRoot->left = unbalancedNode;        // left rotate unbalanced node.
    unbalancedNode->right = leftSubTree;              // insert left sub-tree to the right of unbalanced node.
    updateHeight(unbalancedNode);                     // update height of unbalanced node first as it moved to lower level.
    updateHeight(elevatedBranchRoot);                 // update height of elevated branch root second as it moved higher level.
    return elevatedBranchRoot;                        // return the new position of the elevated root.
}
// calculate balance factor
int getBalance(Node *node){
    return node?height(node->left)- height(node->right):0;
}
//update height of the node.
void updateHeight(Node *node){
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    node->height = 1 + (leftHeight>rightHeight?leftHeight:rightHeight);
}
//get height of the node.
int height(Node *node){
    return node? node->height:-1;
}
//delete node from an AVL Tree.
Node* deleteNode(Node* node, int key,bool &found){
    if (!node) return  node;
    if (key < node->key)
        node->left = deleteNode(node->left,key,found);
    else if (key > node->key)
            node->right = deleteNode(node->right,key,found);
        else{
            found = true;
            if (node->left == nullptr){
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr){
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right); //find minimum value in right sub tree (in-order successor).
            node->key = temp->key;
            node->right = deleteNode(node->right,temp->key,found);
        }
        node = balanceTree(node);
    return node;
}
//perform rotations and balance Tree.
Node* balanceTree(Node* unbalancedNode){
        updateHeight(unbalancedNode);
        int balance = getBalance(unbalancedNode);
        bool isNodeUnbalanced = false;
        isNodeUnbalanced = (balance > 1 || balance < -1) ? true:false; // if the node is unbalanced, assign true.
        // return the unbalanced node address after rotations.
        if (isNodeUnbalanced){
            //CASE LL
            if ( (balance > 1) && ( getBalance(unbalancedNode->left) >=0 ) ) // or value<root->left->data // left sub-tree is heavier
                return rotateRight(unbalancedNode);
            //CASE LR
            if ( (balance > 1) && ( getBalance(unbalancedNode->left) < 0 ) ){
                unbalancedNode->left = rotateLeft(unbalancedNode->left);
                return rotateRight(unbalancedNode);
            }
            //CASE RR
            if ( (balance < -1) && ( getBalance(unbalancedNode->right) <=0 ) ) // right sub-tree is heavier
                return rotateLeft(unbalancedNode);
            //CASE RL
            if ( (balance < -1) && ( getBalance(unbalancedNode->right) > 0 ) ){
                unbalancedNode->right = rotateRight(unbalancedNode->right);
                return rotateLeft(unbalancedNode);
            }
        }else return unbalancedNode; //simply return the node address without rotations as node is already balanced.
}
//find minimum value in tree.
Node* findMin(Node* node){
    while ( node && node->left)
        node = node->left;
    return node;
}
//find maximum value in tree.
Node* findMax(Node *node){
    while (node && node->right)
        node = node->right;
    return node;
}
//find parent of a node.
Node* findParent(Node* node, int key){
    if (!node || node->key == key) return node; // base case for empty tree / root node /  leaves.
    if ( (node->left && key == node->left->key) ||
         (node->right && key == node->right->key) ) // base case, if parent node is found.
        return node;
    if (key < node->key )
        return findParent(node->left,key); //recursively traverse to left if value is smaller.
    else
        return findParent(node->right,key); //recursively traverse to right if value is greater.
}
//find left child of a node.
Node* findLeftChild(Node* node){
    return node ? node->left : node;
}
//find right child of a node.
Node* findRightChild(Node* node){
    return node ? node->right : node;
}
// search node by a specific (given) value
Node* findValue(Node *node,int key){  // search function
    if (!node) return node;
    if ( node->key == key) return node;
    if ( key < node->key )
        return findValue(node->left,key);
    else
        return findValue(node->right,key);
}
//display Tree Structure
void displayTreeStructure(Node *node,int space =0,int indent=6){
    if (node){
        space += indent;
        displayTreeStructure(node->right,space);
        cout<<setw(space)<<node->key<<endl;
        displayTreeStructure(node->left,space);
    }
}
//delete all nodes in the tree.
void destroyTree(Node* node){
    if (!node) return;
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}
// count total number of nodes in the tree.
int countNodes(Node *node){
    if (!node) return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}
// count nodes at a specific (given) level.
int countNodestAtLevel(Node* node, int level){
    if (!node) return 0;
    if (level == 0) return 1;
    return countNodestAtLevel(node->left,level-1) + countNodestAtLevel(node->right,level-1);
}
// find depth of a node.
int findDepth(Node *node,int key,int depth=0){
    if (!node) return -1;
    if (key == node->key) return depth;
    if (key < node->key)
        return findDepth(node->left,key, ++depth);
    else
        return findDepth(node->right,key, ++depth);
}
// perform breadth first search traversal of the tree.
void BFS_traversal(Node* node){
    queue<Node*> q;
    q.push(node);
    while( !q.empty() ){
        Node* trNo = q.front(); q.pop();
        cout<<trNo->key<<", ";
        if (trNo->left) q.push(trNo->left);
        if (trNo->right) q.push(trNo->right);
    }
}
// perform depth first search traversal using pre-order traversal(PLR).
void preOrder(Node* node){
    if (node){
        cout<<node->key<<", ";
        preOrder(node->left);
        preOrder(node->right);
    }
}
// perform depth first search traversal using In-order traversal(LPR).
void inOrder(Node* node){
    if (node){
        inOrder(node->left);
        cout<<node->key<<", ";
        inOrder(node->right);
    }
}
// perform depth first search traversal using post-order traversal(LRP).
void postOrder(Node* node){
    if (node){
        postOrder(node->left);
        postOrder(node->right);
        cout<<node->key<<", ";
    }
}

public:
    int choice;
    //constructor for AVL Tree.
    AVL():root(nullptr),choice(1){}
    //destructor for AVL Tree.
    ~AVL(){ if(root) destroyTree(root); }
    //Insert Node in AVL Tree (Public Wrapper).
    bool treeIsEmpty(){
        if (!root)  cout<<"\n tree is empty \n";
        return !root;
    }
    void insertNode(){
        bool duplicate = false;
        cout<<"\n enter value for insertion = "; cin>>value;
        root = insertNode(root,value,duplicate);
        duplicate?cout<<"\n duplicate ignored":cout<<"\n value inserted successfully. \n";
    }
    //Delete Node from AVL Tree (Public Wrapper).
    void deleteNode(){
        if (treeIsEmpty()) return;
        bool found=false;
        cout<<"\n enter value for deletion = "; cin>>value;
        root = deleteNode(root, value, found);
        found ? cout<<"\n value delete successfully \n" : cout<<"\n value not found in Tree \n";
    }
    //public wrapper of the display tree structure( ).
    void displayTreeStructure(){
        if (treeIsEmpty()) return;
        cout<<"\n Root Node at Left, Right Child at Top, Left Child at Bottom \n\n";
        displayTreeStructure(root);
        cout<<endl;
    }
    //destroy Tree
    void destroyTree(){
        if (treeIsEmpty()) return;
        destroyTree(root);
        root = nullptr;
        cout<<"\n tree successfully deleted \n";
    }
    //find a value in AVL Tree.
    void findValue(){
        if (treeIsEmpty()) return;
        cout<<"\n enter value to find in the tree = "; cin>>value;
        findValue(root,value) ? cout<<"\n value found in Tree\n" : cout<<"\n value not found in Tree\n";
    }
    //find smallest value in the tree
    void findMin(){
        if (treeIsEmpty()) return;
        Node *minimum = findMin(root);
        cout<<"\n smallest value in the Tree = "<<minimum->key;
    }
    //find largest value in the tree
    void findMax(){
        if (treeIsEmpty()) return;
        Node *maximum = findMax(root);
        cout<<"\n smallest value in the Tree = "<<maximum->key;
    }
    //find parent of a node.
    void findParent(){
        if (treeIsEmpty()) return;
        cout<<"\n enter value of the child node for finding parent = "; cin>>value;
        if (findValue(root,value)){ // display parent only if value exists in the tree.
            Node* parent = findParent(root,value);
            if (parent) {
                (parent == root) ? cout<<"root node" : cout<<" parent of the node = "<<parent->key;
            }
        }
        else // do not find parent if value does not exist in the tree.
            cout<<"\n value does not exist in the Tree";
    }
    // find left child of a node.
    void findLeftChild(){
        if (treeIsEmpty()) return;
        cout<<"\n enter value of the parent the node for finding left child = "; cin>>value;
        Node* parent = findValue(root,value);
        if (parent){
           Node* leftChild = findLeftChild(parent);
           leftChild ? cout<<" left child of the node: "<<value<<" is: "<< leftChild->key : cout<<" Left child does not exist";
        }
        else
            cout<<"\n value not present in the tree ";
    }
    // find right child of a node.
    void findRightChild(){
        if (treeIsEmpty()) return;
        cout<<"\n enter value of the parent the node for finding right child = "; cin>>value;
        Node* parent = findValue(root,value);
        if (parent){
         Node* rightChild = findRightChild(parent);
         rightChild ? cout<<" right child of the node: "<<value<<" is: "<< rightChild->key : cout<<" right child does not exist";
        }
        else
            cout<<"\n value not present in the tree ";
    }
    //count all nodes in the AVL tree.
    void countNodes(){
        if (treeIsEmpty()) return;
        int numberOfNodes = countNodes(root);
        cout<<"\n total number of nodes in the Tree = "<<numberOfNodes;
    }
    // count nodes at a specific level.
    void countNodestAtLevel(){
        if (treeIsEmpty()) return;
        int level=0, numberOfNodes=0;
        cout<<"\n enter level for counting nodes = "; cin>>level;
        if (level>=0){
            numberOfNodes = countNodestAtLevel(root,level);
            cout<<"\n number of nodes at level "<<level<<" are = "<<numberOfNodes;
        }
        else
            cout<<"\n invalid level number, please try again!";
    }
    // perform breadth first search traversal (level-order traversal) of the tree.
    void BFS_traversal(){
        if (treeIsEmpty())return;
        cout<<"\n\t Breadth First Traversal (Level-Order Traversal) of tree: \n\t";
        BFS_traversal(root);
        cout<<endl;
    }
    // perform depth first search traversal using pre-order travesal(PLR).
    void preOrder(){
        if (treeIsEmpty()) return;
        cout<<"\n pre-order traversal of the Tree: \n\t ";
        preOrder(root);
        cout<<endl;
    }
    // perform depth first search traversal using in-order travesal(LPR).
    void inOrder(){
        if (treeIsEmpty()) return;
        cout<<"\n In-order traversal of the Tree: \n\t ";
        inOrder(root);
        cout<<endl;
    }
    // perform depth first search traversal using post-order travesal(LRP).
    void postOrder(){
        if (treeIsEmpty()) return;
        cout<<"\n post-order traversal of the Tree: \n\t ";
        postOrder(root);
        cout<<endl;
    }
    //display menu of AVL ADT.
    void displayMenu(){
        cout<<"\n  ********AVL TREE ADT  ********\n"<<"\t(1) for Insertion\n"<<"\t(2) for Deletion\n"
        <<"\t(3) for Display Tree Strucure\n"<<"\t(4) for Delete Tree\n"<<"\t(5) for Searching Tree\n"
        <<"\t(6) for Searching smallest value in Tree\n"<<"\t(7) for Searching largest value in Tree\n"
        <<"\t(8) for Counting Nodes in Tree\n"<<"\t(9) for finding depth of a Node in Tree\n"
        <<"\t(10)for Counting Nodes at a specific level in Tree\n"<<"\t(11)for finding parent of a node in Tree\n"
        <<"\t(12)for finding left child of a node in Tree\n"<<"\t(13)for finding right child of a node in Tree\n"
        <<"\t(14)for performing Breadth First Search Traversal of Tree\n"
        <<"\t(15)for performing Depth First Search Traversal of Tree using Pre-Order Traversal\n"
        <<"\t(16)for performing Depth First Search Traversal of Tree using In-Order Traversal\n"
        <<"\t(17)for performing Depth First Search Traversal of Tree using Post-Order Traversal\n"
        <<"\t(0) for Exit\n";
        cout<<"\n enter choice = ";
        cin>>choice;
    }
    //find depth of a node.
    void findDepth(){
        if (treeIsEmpty()) return;
        int value=0; cout<<"\n enter value of the node for finding its depth = "; cin>>value;
        int depth = findDepth(root,value);
        if (depth == -1)
            cout<<"\n node not found\n";
        else
            cout<<"\n depth of the node = "<<depth;
    }
    //clear Menu
    void clearMenu(){
        if (choice){
            cout<<"\n press any key to continue ";
            _getch(); system("CLS");
        }
    }
};
int main(){
    AVL tree;
    do{
        tree.displayMenu();
        switch(tree.choice){
            case INSERTION: tree.insertNode();
                break;
            case DELETION: tree.deleteNode();
                break;
            case DISPLAY: tree.displayTreeStructure();
                break;
            case DELETE_TREE: tree.destroyTree();
                break;
            case EXIT:
                break;
            case SEARCH: tree.findValue();
                break;
            case FIND_MINIMUM: tree.findMin();
                break;
            case FIND_MAXIMUM: tree.findMax();
                break;
            case COUNT_NODES: tree.countNodes();
                break;
            case FIND_DEPTH: tree.findDepth();
                break;
            case COUNT_NODES_AT_LEVEL: tree.countNodestAtLevel();
                break;
            case FIND_PARENT: tree.findParent();
                break;
            case FIND_LEFT_CHILD: tree.findLeftChild();
                break;
            case FIND_RIGHT_CHILD: tree.findRightChild();
                break;
            case BREADTH_FIRST_TRAVERSAL: tree.BFS_traversal();
                break;
            case DEPTH_FIRST_SEARCH_PRE: tree.preOrder();
                break;
            case DEPTH_FIRST_SEARCH_IN: tree.inOrder();
                break;
            case DEPTH_FIRST_SEARCH_POST: tree.postOrder();
                break;
            default: cout<<"\n please enter appropriate choice \n";
                break;
        }
        tree.clearMenu();
    } while(tree.choice);
cout<<endl<<endl;
return 0;
}
