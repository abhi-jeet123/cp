


//tree traversal

        10
       /  \
      20  30
     /  \   \
    40 50   60
      /  \
    70  80

//Inorder: 40 20 70 50 80 10 30 60
//Preorder: 10 20 40 50 70 80 30 60
//Postorder: 40 70 80 50 20 60 30 10



//Inorder traversal

void inorder(node*root){
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);

    return;
}

//Preorder traversal

void preorder(node*root){
    if(root==NULL)return;
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
    return;
}

//Postorder traversal

void postorder(node*root){
    if(root==NULL)return;
    postorder(root-left);
    postorder(root->right);
    cout<<root->data;
    return;
}