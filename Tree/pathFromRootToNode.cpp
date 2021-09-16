/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


 bool path(TreeNode* root,int B,vector<int> &len1){
    if(root==NULL)return false;
    len1.push_back(root->val);
    if(root->val==B or path(root->left,B,len1) or path(root->right,B,len1))
      return true;
    len1.pop_back();
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int>len1;
    bool flag=path(A,B,len1);
    return len1;
}
