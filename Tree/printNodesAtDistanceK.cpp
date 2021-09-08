


//print nodes at distance k problem

//we recursively call for left and right subtree and reducing distance by 1,as 
//we are going down,and as we reach the the kth level level the value of k will
//be 0 ,and we will print all such nodes.

void printNodesAtDistanceK(node*root,int k){
    if(root == NULL)return;
    if(k==0)cout<<root->data<<" ";
    else{
       printNodesAtDistanceK(root->left,k-1);
       printNodesAtDistanceK(root->right,k-1);
    }
    
    return;
}