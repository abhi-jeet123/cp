

//Count of unival tree

int univalTree(node* root,int &count){
    if(root==NULL)return INT_MIN;
    if(root->left==NULL and root->right==NULL){
        count++;
        return root->data;
    }
    int left=univalTree(root->left,count);
    int right=univalTree(root->right,count);

    if(left==INT_MIN and right==root->data or right==INT_MIN and left==root->data or
       left==right and left==root->data){
           count++;
           return root->data;
       }
       return INT_MAX;
}

int countUnivalTree(node*root){
    int count =0;
    int num=univalTree(root,count);
    return count;
}