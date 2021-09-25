

//two sum in bst
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

// APPROACH:we will do a dfs and store every encountered element in set,and once we 
// find the k-curr_root->val is present in our set,then we return true.

class Solution {
public:
    
    set<int> s;
    bool dfs(TreeNode* root,int k){
    if(root==NULL)return false;

    if(s.find(k-root->val)!=s.end())return true;
    s.insert(root->val);
    return dfs(root->left,k) or dfs(root->right,k);
}
    
    bool findTarget(TreeNode* root, int k) {
        return dfs(root,k);
        
    }
};