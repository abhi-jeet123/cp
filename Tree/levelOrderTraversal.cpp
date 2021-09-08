


//maximum depth of binary tree(same as height of binary tree).
//as maximum depth of tree is height of tree.

//2.level order traversal of binary tree(i.e breadth first traversal of binary tree).

void levelOrderTraversal(node*root){
    if(root==NULL)return;
    queue<node*> q;
    q.push(root);
    while(q.empty()==false){
        node *curr=q.top();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left)q.push(curr->left);
        if(curr->right)q.push(curr->right);
    }
    return;
}

//3.line by line printing of level order traversal

void levelOrderTraversal(node*root){
    if(root==NULL)return;
    queue<node*> q;
    q..push(root);
    while(!q.empty()){
        int count=q.size();
        for(int i=0;i<count;++i){
            node *curr=q.top();
            q.pop();
            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);
        }cout<<endl;
    }
    return;
}
