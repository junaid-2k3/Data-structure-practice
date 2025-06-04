// program to show whethter an existing tree is an avl tree or not 
// an avl tree is a tree having balance factor of a node equal to -1 ,0 ,1 , other than these 
// 
#include <iostream>
using namespace std;

struct Node {
    int data;
    int height;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
void updateHeight(Node *node){
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    node->height = 1 + (leftHeight>rightHeight?leftHeight:rightHeight);
}
//get height of the node.
int height(Node *node){
    return node? node->height:-1;
}
int getBalance(Node* root){
    if(!root){
        return 0;
    }
    
    return root->left->height-root->right->height;
}
bool isAVL(Node* root){

}