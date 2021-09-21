

//Insert in binary search tree

void insertBST(node*root,int val){
    if(root==NULL)return new node(val);

    else if(root->val>val){
         root->left=insertBST(root->left,val);
    }
    else if(root->right<val)
        root->right=insertBST(root->right,val);

    return root;
}