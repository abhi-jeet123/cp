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
    int pre;
    map<int,int> mp;
    
    //int search(int val)
    
    TreeNode* solve(vector<int>& inorder,vector<int>& postorder,int s,int e){
        if(s>e)return NULL;
        TreeNode* root=new TreeNode(postorder[pre--]);
        if(s==e)return root;
        int index=mp[root->val];
        root->right=solve(inorder,postorder,index+1,e);
        root->left=solve(inorder,postorder,s,index-1);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        pre=inorder.size()-1;
        for(int i=0;i<inorder.size();++i){
            mp[inorder[i]]=i;
        }
        return solve(inorder,postorder,0,pre);
    }
};