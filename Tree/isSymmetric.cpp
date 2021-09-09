

//symetric tree(mirror image of itself)

//3 conditions for two tree to bhi mirror image

//1.there root node must be same.
//2.left subtree of left tree should same as right subtree of right tree.
//3.right subtree of left tree should same as left subtree of right tree.


bool isMirror(node *root1,node *root2){
    if(root1==NULL and root2==NULL)return true;
    if(root1 and root2 and root1->key==root2->key){
        return isMirror((root->left,root->right) and isMirror(root->right,root->left));
    }
}


bool isSymetric(node*root){
    return isMirror(root,root);
}