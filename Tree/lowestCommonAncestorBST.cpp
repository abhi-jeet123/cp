

//LOWEST COMMON ANCESTOR OF BINARY SEARCH TREE

node* lcaBST(node*root,int n1,int n2){
    if(root==NULL)return NULL;
    if(root->data>n1 and root->data>n2){
        return lcaBST(root->left,n1,n2);
    }
    if(root->data<n1 and root->data<n2){
        return lcaBST(root->right,n1,n2);
    }
    return root;
}