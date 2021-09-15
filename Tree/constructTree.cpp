

//construct binary from inorder and preorder traversal
                                               0        n-1
node*constructTree(int *pre,int *inorder,int start,int end){
    if(start>end)return NULL;

    static int preIndex=0;

    node*root=new node(pre[preIndex++]);

    if(start==end)return root;//case of leaf node.

    //now second part is two find its left and right subtree
    //as we have find root, so in its inorder we can find its root index,
    // and left of which in inorder will represent its left subtree,and 
    //right part will represent right subtree.
    int index;
    for(int i=start;i<=end;++i){
        if(root->val==inorder[i]){
            index=i;
            break;
        }
    }
    root->left=constructTree(pre,inorder,start,index-1);
    root->right=constructTree(pre,inorder,index+1,end);

    return root;

}