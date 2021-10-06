/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ser="";
        if(root==NULL)return ser;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
        TreeNode* curr=q.front();
        q.pop();
        if(curr==NULL)ser.append("#,");
        else ser.append(to_string(curr->val)+',');

        if(curr!=NULL){
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return ser;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)return NULL;
        stringstream s(data);
        queue<TreeNode*> q;
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty()){
        TreeNode* curr=q.front();
        q.pop();
        getline(s,str,',');
        if(str=="#"){
            curr->left=NULL;
        }else {
            TreeNode* leftTreeNode=new TreeNode(stoi(str));
            curr->left=leftTreeNode;
            q.push(leftTreeNode);
        }

        getline(s,str,',');
        if(str=="#"){
            curr->right=NULL;
        }else{
            TreeNode* rightTreeNode=new TreeNode(stoi(str));
            curr->right=rightTreeNode;
            q.push(rightTreeNode);
        }

    }
    return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));