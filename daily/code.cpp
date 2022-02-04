#include "bits/stdc++.h"
using namespace std;

class node{
    public:
    
    node*left,*right;
    int val;
    node(int _val){
        val=_val;
        left=NULL;
        right=NULL;
        
    }
};

node*build_btree(){
    int x;
    cin>>x;
    if(x==-1)
    return NULL;
    node*curr=new node(x);
    curr->left=build_btree();
    curr->right=build_btree();
    return curr;
    
}


string serialize(node *root){
    string ser="";
    if(root==NULL)return ser;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* curr=q.front();
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

void solve(){
	node* root=build_btree();
	string ser=serialize(root);
	cout<<ser<<endl;
}

int main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	solve();

    return 0;
} 
