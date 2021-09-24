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
    map<int,int> mp;
    

    
    void preorder(TreeNode*root){
        if(root==NULL)return ;
        
        mp[root->val]++;
        preorder(root->left);
        preorder(root->right);
        
        return;
    }
    
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)return ans;
        preorder(root);
        vector<pair<int,int>> freq;
        for(auto c:mp){
            freq.push_back(make_pair(c.second,c.first));
        }
        sort(freq.begin(),freq.end(),greater<pair<int,int>>());
        int fr=freq[0].first;
        ans.push_back(freq[0].second);
        for(int i=1;i<freq.size();++i){
            if(freq[i].first==fr)ans.push_back(freq[i].second);
        }
        return ans;
    }
};