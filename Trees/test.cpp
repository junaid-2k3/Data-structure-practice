#include <iostream>
using namespace std;

struct Node{
    Node* left;
    Node* right;
    int data;
     
    Node(int val):left(nullptr),right(nullptr),data(val){}

};

class BST{
    private:
    Node* root;
    public:
    BST():root(nullptr){}

    Node* insert(Node* root, int val){
        if(root==nullptr){return new Node(val);}
        else{
            if(val<root->data){root->left=insert(root->left,val);}
            else{
                root->right=insert(root->right,val);
            }
            return root;
        }
    }
    void insert(int val){
        root=insert(root,val);
    }
    void preorder(Node* root) {
        if (root == nullptr) return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    void preorder(){
       preorder(root);}
    Node* search(Node* root,int target){
        if(root==nullptr || root->data==target){return root;}
        else{
            if(target<root->data){search(root->left,target);}
            else{
                search(root->right,target);
            }
        }
    }
    void search(int val){
       Node* searchedNode=search(root,val);
       cout<<"the value "<<searchedNode->data<<"is found"<<endl;
    }
    Node* find_min(Node* root){
        if(root==nullptr){
            return root;}
    
            while(!root->left){
                 root=root->left;
            }
           
            return root;
    }
    Node* deleteNOde(Node* root, int key){
        if(root==nullptr)return root;
        if(key<root->data){
            root->left=deleteNOde(root->left,key);
        }else if(key>root->data){
            root->right=deleteNOde(root->right,key);
        }else{
            // case 1 (when there is only one branch of a tree )
            if(root->left==nullptr){
                Node* temp=root->right;
                delete root;
                return temp;
            }else if(root->right==nullptr){
                Node* temp=root->left;
                delete root;
                return temp;
            }else{
                Node* temp=find_min(root->right);
                root->data=temp->data;
                root->right=deleteNOde(root->right,temp->data);   
            }
            
        }
        return root;
    }
    void Delete(int val){
        deleteNOde(root,val);
    }
};
int main(){
    BST tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(7);
    tree.insert(8);
    tree.insert(6);
    tree.insert(2);
    tree.insert(1);
    

    tree.preorder();cout<<"\n";
    tree.search(8);
    cout<<endl;
    tree.Delete(4);
    cout<<"  --------------------"<<endl;
    tree.preorder();
}