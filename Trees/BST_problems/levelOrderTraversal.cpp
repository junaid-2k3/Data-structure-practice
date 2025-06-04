#include <iostream>
#include <queue>
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
void LevelOrderTraversal(Node* root){
    if(!root){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* current=q.front();
        q.pop();
        cout<<current->data;
        if(root->left){
            q.push(current->left);
        }
        if(root->right){
            q.push(current->right);
        }
        cout<<endl;
    }
}
int main(){
    Node* root = new Node(24);
    root->left = new Node(15);
    root->right = new Node(4);
    root->left->left = new Node(2);
    root->left->right = new Node(22);
    root->left->right->left = new Node(12);
    root->right->left = new Node(6);
    root->right->right = new Node(10);
    LevelOrderTraversal(root);

}