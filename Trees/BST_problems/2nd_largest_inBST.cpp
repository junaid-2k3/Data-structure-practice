Node*  kthsmallestHelper(Node* root ,int k){
    if(!root){
        return nullptr;
    }
    kthsmallestHelper(root->left,int k);
    k--;
    if(k==0){
        return root;  // if i want to return the root and if i want to return the value then i wil store the 
    }
    kthsmallestHelper(root->right);
}