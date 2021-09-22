

//Delete Node in BST

node* getSucc(node* root){
    node* curr=root->right;
    while(curr!=NULL and curr->left!=NULL)
       curr=curr->left;
    return curr;
}

node *deleteNode(node *root,int x){
    if(root==NULL)return root;
    if(root->val>x){
        //it means node to be deleted lies on the left side
        root->left=deleteNode(root->left,x);
        //assignment is used so as to attach the lower part of deleted node
    }else if(root->val<x){
        //it means node to be deleted lies on the right side
        root->right=deleteNode(root->right,x);
    }else{
         //it means that node to be deleted is root itself
         //so here there could be three cases,either left suftree is empty
         if(root->left==NULL){
             node*temp=root->right;
             delete(root);
             return temp;
         }else if(root->right==NULL){
             //case when there is right subtree empty
             node*temp=root->left;
             delete(root);
             return temp;
         }else{
             //when both left and right subtree is present
             //we will find the root succ and replace root val with succ val,and recursively call the function to delete succ.
             node*succ=getSucc(root);
             root->val=succ->val;
             root->right=deleteNode(root->right,succ->val);
         }

    }
    return root;
}