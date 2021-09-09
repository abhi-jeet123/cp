

//Sum of all the numbers that are formed from root to leaf paths

// Approach:The idea behind is simple ,we will simply traverse in
// preorder manner and every time we reach a node we update our number 
// formed till that particular node (val*10 +root->key),and we will pass 
// on that new value to the next left subtree and right subtree recursively,
// and finaly when we reach the leaf node we will passon(return) that formed number 
// through that particular leaf node.


int helperFunc(node*root,int val){
    if(root==NULL)return 0;
   
    val=val*10 + root->data;
    //updated value to be passed to the lower subtree(i.e number formed till this node.)


    if(root->left==NULL and root->right==NULL)return val;
    //case when we reach leaf node and its time to addon our calculated val.
    return helperFunc(root->left,val) + helperFunc(root->right,val);

}

int rootToLeafPathSum(node*root){
    return helperFunc(root,0);
}