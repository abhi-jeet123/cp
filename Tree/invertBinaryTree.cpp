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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)return root;
        invertTree(root->left);
        invertTree(root->right);
        TreeNode*temp=root->left;
        root->left=root->right;
        root->right=temp;
        
        return root;
    }
};

// (1)  Call Mirror for left-subtree    i.e., Mirror(left-subtree)
// (2)  Call Mirror for right-subtree  i.e., Mirror(right-subtree)
// (3)  Swap left and right subtrees.
//           temp = left-subtree
//           left-subtree = right-subtree