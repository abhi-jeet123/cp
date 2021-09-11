

//TOP VIEW OF BINARY TREE

vector<int> topView(node *root){
    vector<int>ans;
    if(root==NULL)return NULL;
    map<int,int> mp;
    queue<pair<int,node*>> q;
    q.push(make_pair(0,root);
   // mp[hd]=root->val;
    while(!q.empty()){
        pair<int,node*> curr=q.front();
        q.pop();
        int hd=curr.first;
        if(mp.find(hd)==mp.end())mp[hd]=curr.second->val;
        if(curr.second->left)q.push(hd-1,curr.second->left);
        if(curr.second->right)q.push(hd+1,curr.second->right);
    }
  for(auto c:mp)ans.push_back(c.second);
  return ans;

}