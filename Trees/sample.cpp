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

int sumInRangBst(Node* root,int Llimit,int Hlimit,){
    if(!root){
        return 0;
    }
    if(root->data<Llimit){
        return sumInRangBst(root->right,Llimit,Hlimit);
    }
    if(root->data>Hlimit){
        return sumInRangBst(root->left,Llimit,Hlimit);
    }
        return   root->data +  sumInRangBst(root->left,Llimit,Hlimit) + sumInRangBst(root->right);
}