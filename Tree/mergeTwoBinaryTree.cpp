


//MERGE TWO BINARY TREE

// APPROACH:We can traverse both the given trees in a preorder fashion.
//  At every step, we check if the current node exists(isn't null) for
//   both the trees. If so, we add the values in the current nodes of 
//   both the trees and update the value in the current node of the first
//    tree to reflect this sum obtained. At every step, we also call the
//     original function mergeTrees() with the left children and then with
//      the right children of the current nodes of the two trees. If at any
//       step, one of these children happens to be null, we return the child
//        of the other tree(representing the corresponding child subtree) to
//         be added as a child subtree to the calling parent node in the
//          first tree. At the end, the first tree will represent the 
//          required resultant merged binary tree.

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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL)return root2;
        if(root2==NULL)return root1;
        root1->val+=root2->val;
        root1->left=mergeTrees(root1->left,root2->left);
        root1->right=mergeTrees(root1->right,root2->right);
        //we are using equals sign here to join the lower left aur right 
        //half in case if the node is not present in firsts tree and present 
        //in second tree,so it must be added as a new node to the first tree.
        return root1;
    }
};
