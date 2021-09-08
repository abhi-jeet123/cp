


//height of binary tree

//height of a binary tree is the number of nodes between the longest path from 
//root to leaf.

//recursively compute for height for left subtree and right subtree ,and take 
//the height of max height subtree and 1 for the current root node.

int height(node*root){
    if(root==NULL)return 0;
    //height of null tree is 0,or when no node is remaining i.e passed through leaf node then return 0 from there.
    int lh=height(root->left);
    int rh=height(root->right);

    return max(lh,rh)+1;
}


//differnce between depth and height of tree
//The depth of a node is the number of edges from the node to the tree's root node.
// A root node will have a depth of 0. The height of a node
// is the number of edges on the longest path from the node to a leaf