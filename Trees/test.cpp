#include <iostream>
#include <climits>
#include <vector>
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

    Node* insertHelper(Node* root, int val){
        if(root==nullptr){return new Node(val);}
        else{
            if(val<root->data){root->left=insertHelper(root->left,val);}
            else{
                root->right=insertHelper(root->right,val);
            }
            return root;
        }
    }
    
    void preorder(Node* root) {
        if (root == nullptr) return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    void inorder(Node* root){
        if(root==nullptr){
            return;
        }
        inorder(root->left);
        cout<<root->data;
        inorder(root->right);
    }
    
    Node* search(Node* root,int target){
        if(root==nullptr || root->data==target){return root;}
        else{
            if(target<root->data){search(root->left,target);}
            else{
                search(root->right,target);
            }
        }
    }
    
    Node* find_min(Node* root){
        if(root==nullptr){
            return root;}
    
            while(!root->left){
                 root=root->left;
            }
           
            return root;
    }
    void presus(Node* root,Node*& pre,Node*& sus,int key ){// funciton to calcualte the predesessor and successor 
        if(root->data==key){
            if(root->left){
                Node* temp=root->left;
            while(temp){
                temp=temp->right;
            }pre=temp;
            }
            
            if(root->right){
                Node* temp=root->right;
                while(temp){
                    temp=temp;
                }
            }
        }
        if(root->data>key){
            sus=root;
            presus(root->left,pre,sus,key);        
        }else{
            pre=root;
            presus(root->right,pre,sus,key);
        }

    }
    void deleteNode(Node* root , int val ){
        if(!root){return;}
        Node* temp=root;
        while(temp->data=val){
            deleteNode(root->left,val);
            deleteNode(root->right,val);
        }if(!root->left && !root->right){
            delete root;
        }else if(root->right==nullptr || root->left==nullptr){
            if(!root->left){
                Node* temp=root->right;
                delete root;
                return;}
            else{
                Node* temp=root->left;
                delete root;
                return;
            }

        }
    }


    void printRangeHelper(Node* root, int L, int R) {
        if (root == nullptr) return;
        
        if (root->data > L) // checks if the root is in the range from the lower limit
            printRangeHelper(root->left, L, R);//recursivley call the laft ,untill left becomes smaller than k1(lower limit)
        
        if (root->data > L && root->data < R) // check range
            cout<<root->data<<" "; // print the value if the node is in range 
        
        if (root->data < R) // check for range from the higher limit 
            printRangeHelper(root->right, L, R); // untill right is greater than the limit 
    }
    
      bool isBSTHelper(Node* root, int minVal, int maxVal) {
        if (root == nullptr) return true;
        
        if (root->data <= minVal || root->data >= maxVal)
            return false;
        
        return isBSTHelper(root->left, minVal, root->data) &&
               isBSTHelper(root->right, root->data, maxVal);
    }
    

    public:            //////////////////////
    void insert(int val){
        root=insertHelper(root,val);
    }
     void Delete(int val){
        deleteNode(root,val);
    }
    Node* findMin(){
        return find_min(root);
    }
    void search(int val){
       Node* searchedNode=search(root,val);
       cout<<"the value "<<searchedNode->data<<"is found"<<endl;
    }
    void preorder(){
       preorder(root);}

    void inorder(){
        inorder(root);
    }
     void findPredesessorAndSuccessor(int val){
        int pred;
        int succe;
        void presus(Node* root ,int& pred,int& succe,int val);
        cout<< "key :"<<val<<endl;
        cout<< "pred :"<<pred<<endl;
        cout<< "succe :"<<succe<<endl;
     }

     void printrangenodes(int k1,int k2){
       printRangeHelper(root,k1,k2);
     }

        bool isbst(){
    int min = INT_MAX;
    int max = INT_MIN;
        return isBSTHelper(root,max,min);
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
    tree.inorder();
     if(tree.isbst()){
        cout<<"the tree is a binarry search tree"<<endl;
     }else{
        cout<<"the tree is not bst "<<endl;
     }
     cout<<"range" <<endl;
     tree.printrangenodes(3,6);

    
}