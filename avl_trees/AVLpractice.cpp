#include <iostream>
#include <iomanip>
using namespace std;

struct Node{
    int data;
    int height; // to keep track of every nodes height for balancing 
    Node* left;
    Node* right;  
    Node(int value):data(value),height(0),left(nullptr),right(nullptr){}
    
};

class Avl{
    private:
    Node* root;
    int value;

    int height(Node* root){  //  returns height 
        return root? root->height : -1;
    }

    int updateHeight(Node* root){   //calculate height 
        if(root == nullptr){
            return 0;
        }
        int leftheight=height(root->left);
        int rightheight=height(root->right);
        return max(leftheight,rightheight)+1;
    }

    int balanceFactor(Node* root){
        return height(root->left)-height(root->right);
    }
    Node* rotateLeft(Node* root){
        Node* EBR=root->right;
        Node* LST=EBR->left;
        EBR->left=root;
        root->right=LST;
        updateHeight(EBR);
        updateHeight(root);
        return EBR;
    }
    Node* rotateRight(Node* root){
        Node* EBR=root->left;
        Node* RST=EBR->right;
        EBR->right=root;
        root->left=RST;
        updateHeight(EBR);
        updateHeight(root);
        return EBR;
    }
    Node* BalanceNode(Node* root){
        updateHeight(root);
        int balance=balanceFactor(root);
        bool IsNodeUnbalanced=false;
        IsNodeUnbalanced=(balance>1 || balance <-1)? true : false ;
        if(IsNodeUnbalanced){
        //LL case of ratation (single rotation on the right side)
        if(balance>1 && balanceFactor(root->left)>=0){// or value<root->left->data
            return rotateRight(root);
        }
        // LR case (double rotation ,first on child on right then left on the unbalanced node )
        if(balance>1 && balanceFactor(root->left)<0 )// or value >root->left->data}
            root->left=rotateRight(root->left);
            return rotateLeft(root);
        //RR case (single rotation on the unbalanced node)
        if(balance<-1 && balanceFactor(root->right)<=0){ // value >root->right->data
            return rotateLeft(root);
        }
        //RL case (double rotation ,chile rotates to the right and unbalanced node to the left)
        if(balance<=-2 && balanceFactor(root->right)>0){ // or value<root->right-data
            root->right=rotateRight(root->right);
            return rotateLeft(root);
        }}
        else{
            return root;} // if node is balanced then simply return the node 
    }
        // private helper funciton for insert
    Node* insert(Node* root ,bool& duplicate ,int value ){// implementation of insert function
            if(!root)
            return new Node(value);
        if(value<root->data){
            root->left=insert(root->left,duplicate,value);
        }
        if(value>root->data){
            root->right=insert(root->right,duplicate,value);
        }
        if(value==root->data){// this is the condition for identifying duplication 
           duplicate=true;
            return root;
        }
        root=BalanceNode(root);
        return root;
    }
    void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void displayTreeStructure(Node* node, int space = 0, int indent = 6) {
    if (node == nullptr)
        return;

    space += indent;

    // Process right child first
    displayTreeStructure(node->right, space);

    // Print current node after space
    cout << setw(space) << node->data << "(h=" << node->height << ")" << endl;

    // Process left child
    displayTreeStructure(node->left, space);
}


    public:///////////////////////////////////////////////////////////////////////////////////////////////////////////
    Avl():root(nullptr),value(0){} // constructor for initialization of root 
// insertion in avl tree 
void insert(int val){ // this is the public wrapper for the function 
    bool duplicate=false;
    root=insert(root,duplicate,val);
    if(duplicate){
        cout<<"duplicate element ::::"<<endl;
    }else{
        cout<<"element inserted "<<endl;
    }
}

void displayInorder(){
    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;
}

void treedisplay(){
    displayTreeStructure(root);
}



};
int main() {
    Avl tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30); // This should trigger a rotation (Right-Right case)
    tree.insert(25); // This may trigger RL rotation
    tree.insert(5);  // Left side
    tree.insert(15);
    tree.insert(20); // Duplicate test
    tree.displayInorder();
    tree.treedisplay();


    return 0;
}
