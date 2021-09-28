

//Inorder Successor of binary search tree

// Approach:There can be two case,
// i)if the right of given node is present ,using getMin func we can easily return the ans
// ii)right is null,then we can go towards left when curr nodes val is less than
// that of given node,and wil be keep updating the ans,every time we encountered 
// a greater node value,and at last we will reach our ans.

node* getMin(node* root){

    node* curr=root;
    while(curr->left != NULL)curr=curr->left;

    return curr;
}

node* inorderSucc(node* root,node *x){
    if(root==NULL)return NULL;

    if(x->right != NULL)return getMin(root->right);

    node*succ = NULL;

    while(root!=NULL){
        if(root->val > x->val){
            succ=root;
            root=root->left;
        }else if(root->val < x->val){
            root=root->right;
        }else break;
    }
    return succ;
}