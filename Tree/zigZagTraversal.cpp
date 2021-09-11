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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> vec;
        int res=0;
         if(root==NULL)return vec;
        int toggle=0;
        while(!q.empty()){
            int siz=q.size();
            vector<int> temp;
            for(int i=0;i<siz;++i){
                TreeNode* curr=q.front();
                q.pop();
                temp.push_back(curr->val);
                if(curr->left!=NULL)q.push(curr->left);
                if(curr->right!=NULL)q.push(curr->right);
                
            }if(toggle%2!=0)reverse(temp.begin(),temp.end());
            
            vec.push_back(temp);
            ++toggle;
        }return vec;
    }
};