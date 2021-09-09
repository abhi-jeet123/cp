


//BINARY TREE MAXIMUM PATH SUM

// APPROACH:for each node there can be 4 possiblity:
// we can get maximum from
// i)node itself
// ii)left subtree path sum + node
// iii)right subtree path sum + node
// iv)left subtree path sum + curr_node->val + right subtree path sum
 
int maxPath(node*root){
    if(root==NULL)return 0;
    int ls=maxPath(root->left);
    int rs=maxPath(root->right);
    //recursively traversing the left and right half

    int max_path=max(root->val,max(rs,ls)+root->val);
    //considering ans from first three cases.
    int curr_max=max(max_path,rs+ls+root->val);
    //considering ans from all 4 conditions.

    res=max(res,curr_max);
    //storing the max achieved path sum till now.

    return max_path;
    //why we are returning max_path instead of curr_path?
    //beacuse while we are return from lower half of tree,we are returning the 
    //maximum path sum from its left or right subtree,we could not return 
    //curr_max beacuse it also consider the case of iv) so we cant extend it 
    //further up,as it path is already achived in lower part.
}