

//Flatten binary tree into linked list

// APPROACH:We can do reverse postorder traversal ,and will maintain a prev pointer
// intially pointing to null,ever time when we reach the node,we make its child its
// right and its left as null;

class Solution{
    node *prev==NULL;
    void flattenBinaryTree(node *root){
        if(root==NULL)return NULL;

        flattenBinaryTree(root->right);
        flattenBinaryTree(root->left);
        root->right=prev;//prev is child of root,which should be at right
        root->left=NULL;//to convert it into linked list its left should always be null.
        prev=root;
    }
}