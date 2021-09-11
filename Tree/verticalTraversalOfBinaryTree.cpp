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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)return ans;
        map<int,vector<int>> mp;
        int hd=0;
        queue<pair<TreeNode*,int>>q;
        q.push(make_pair(root,hd));
        while(!q.empty()){
            pair<TreeNode*,int> temp=q.front();
            q.pop();
            TreeNode *curr=temp.first;
            hd=temp.second;
            mp[hd].push_back(curr->val);
            if(curr->left!=NULL)q.push(make_pair(curr->left,hd-1));
            if(curr->right!=NULL)q.push(make_pair(curr->right,hd+1));
        }
        for(auto it:mp){
            vector<int> vec;
            sort(it.second.begin(),it.second.end());
            for(int i=0;i<it.second.size();++i){
                vec.push_back(it.second[i]);
                
            }//sort(vec.begin(),vec.end());
            ans.push_back(vec);
        }
        return ans;
    }
};