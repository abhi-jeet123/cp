


//size of binary tree,i.e total number of number of nodes in binary tree

//total number of nodes from left subtree + total number of nodes from right subtree
//+1(for the node itself)

int sizeOfBinaryTree(node*root){
    if(root==NULL)return 0;

    else{
         int lh=sizeOfBinaryTree(root->left);
         int rh=sizeOfBinaryTree(root->right);

          return lh+rh+1; 
    }
    
    //1 for the count of node itself
}