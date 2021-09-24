

class Solution{
  public:
    /*You are required to complete below method */
    int evalTree(node* root) {
        // Your code here
          if(root==NULL)return 0;

    if(root->left==NULL and root->right==NULL){
        string s=root->data;
        stringstream geek(s);
 
        int x = 0;
        geek >> x;
        return x;
    }
    int left=evalTree(root->left);
    int right=evalTree(root->right);

    if(root->data=="+"){
        return left+right;
    }else if(root->data=="-"){
        return left-right;
    }else if(root->data=="*"){
        return left*right;
    }else return left/right;

   
    }
};