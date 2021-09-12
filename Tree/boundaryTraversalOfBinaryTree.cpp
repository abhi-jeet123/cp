

//BOUNDARY TRAVERSAL OF BINARY TREE

// APPROACH:using these three problems we can easily solve the problem,
// i)visit and push root in our ans vector.
// ii)visit and push all the left boundary nodes except the leaf node.
// iii)visit and push all the leaf elements (preorder fashion).
// iv)visit and push all the right boundary nodes except the leaf nodes.

isLeaf(node*root){
    if(root->left==NULL and root->right==NULL)return true;
    else return false;
}

void addLeftBoundary(node*root,vector<int> &res){
    node*cur=root->left;
    while(cur){
        if(!isLeaf(cur))res.push_back(cur->val);
        if(cur->left)cur=cur->left;
        else cur=cur->right;
    }
    return;
}

void addRightBoundary(node*root,vector<int> &res){
    vector<int> temp;
    node *cur=root->right;
    while(cur){
        if(!isLeaf(cur))temp.push_back(cur->val);
        if(cur->right)cur=cur->right;
        else cur=cur->left;
    }
    reverse(temp.begin(),temp.end());
    for(int i=0;i<temp.size();++i)res.push_back(tremp[i]);
    return;
}

void addLeaf(node*root,vector<int> &res){
    if(isLeaf(root)){
        res.push_back(root->val);
        return;
    }
    if(root->left)addLeaf(root->left);
    if(root->right)addLeaf(root->right);
}

//driver function

vector<int> print Boundary(node*root){
    vector<int> res;
    if(!root)return res;
    if(!isLeaf(root))res.push_back(root->val);
    addLeftBoundary(root,res);
    addLeaf(root,res);
    addRightBoundary(root,res);
    return res;
}