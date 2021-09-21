


//SEARCH VALUE IN BINARY SEARCH TREE

bool searchBST(node* root,int val){
    if(root==NULL)return false;
    if(root->val==val)return true;
    else if(root->val>val){
        return searchBST(root->left,val);
    }else return searchBST(root->right,val);
}