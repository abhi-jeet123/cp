

//LOWEST COMMON ANCESTOR OF BINARY TREE

// APPROACH:(GFG)
// The idea is to traverse the tree starting from the root. If any 
// of the given keys (n1 and n2) matches with the root, then the
//  root is LCA (assuming that both keys are present). If the root
//   doesn’t match with any of the keys, we recur for the left and 
//   right subtree. The node which has one key present in its left
//    subtree and the other key present in the right subtree is the
//     LCA. If both keys lie in the left subtree, then the left
//      subtree has LCA also, otherwise, LCA lies in the right subtree.  

node* lca(node*root,int n1,int n2){
    if(root==NULL)return NULL;
    if(root->key==n1 or root->key==n2){
        return root;
    }
    node*lca1=lca(root->left,n1,n2);
    node*lca2=lca(root->right,n1,n2);

    if(lca1 and lca2)return root;
    (lca1!=NULL)?return lca1:return lca2;
}

