/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode*root){
        if(root==NULL)return INT_MIN;
        if(root->left==NULL and root->right==NULL)return root->val;
        
        int left=solve(root->left);
        int right=solve(root->right);
        
        if(left==INT_MIN and right==root->val or right==INT_MIN and left==root->val
          or left==right and left==root->val){
            return root->val;
        }
        return INT_MAX;
    }
    
    bool isUnivalTree(TreeNode* root) {
        int res=solve(root);
        if(res==root->val or res==INT_MIN)return true;
        else return false;
    }
};