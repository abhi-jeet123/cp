

//find floor of given val in BST

int floor(node*root,int x){
    int res=INT_MAX;
    while(root!=NULL){
        if(root->val==x){
            return root->val;
        }else if(root->val>x){
            root=root->left;
        }else{
            res=root->val;
            root=root->right;
        }
    }
    return res;
}

//Ceil of given val in BST
int CEIL(node*root,int x){
    int res=INT_MIN;
    while(root!=NULL){
        if(root->val==x){
            return root->val;
        }else if(root->val<x){
            root=root->right;
        }else{
            res=root->val;
            root=root->left;
        }
    }
    return res;
}