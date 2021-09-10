


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

// APPROACH: for two numbers to be cousins there should be two condition ,
// i)depth of first node should be same as depth of second node.
// ii)sibling of first node should not be equal to second node(both parent should be different)
// we will simply do dfs and find the depth of the two nodes and also passing there
// parent on each recursive call(will help in finding the parent of x and y).

class Solution {
public:
    int xDepth=-1;
    int yDepth=-2;
    TreeNode *xParent=NULL,*yParent=NULL;
    
    void dfs(TreeNode*root,TreeNode*parent,int x,int y,int depth){
        if(root==NULL)return;
        if(root->val==x){
            xDepth=depth;
            xParent=parent;
        }
        if(root->val==y){
            yDepth=depth;
            yParent=parent;
        }
        dfs(root->left,root,x,y,depth+1);
        dfs(root->right,root,x,y,depth+1);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
     dfs(root,NULL,x,y,0);
     if(xDepth==yDepth and xParent!=yParent)return true ;
    else return false;
    }
};