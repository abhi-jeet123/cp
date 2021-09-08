


//maximum and minimum in binary tree

int maximumInBinaryTree(node*root){
    if(root==NULL)return INT_MIN;

    else{
        return max(maximumInBinaryTree(root->left),
                        max(maximumInBinaryTree(root->right),root->data));
    }
}
//time complexity=O(n);
//Space complexity=O(h);

//minimum in binary tree

int getMin(node*root){
    if(root==NULL)return INT_MAX;
    else{
        return min(root->data,
                   max(getMin(root->left),getMin(root->right)));
    }
}