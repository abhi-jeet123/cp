


//remove node out of range in BST

node* removeNode(node* root,int min,int max){
    if(root==NULL)return NULL;

    root->left=removeNode(root->left,min,max);
    root->right=removeNode(root->right,min,max);

    if(root->key<min){
        node* curr=root->right;
        delete root;
        return curr;
    }else if(root->key>max){
        node* curr=root->left;
        delete root;
        return curr;
    }
     return root;
}