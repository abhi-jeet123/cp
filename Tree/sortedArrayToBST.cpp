#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node*left;
    Node*right;
    Node(int k){
        key=k;
        left=right=NULL;
    }
};

void preorder(Node*root){
    if(root==NULL)return;
    cout<<root->key<<" ";
    preorder(root->left);
    preorder(root->right);
    return;
}

Node* createArray(int *arr,int s,int e){
    if(s>e)return NULL;
    int mid=(s+e)/2;
    Node* root =new Node(arr[mid]);
    root->left=createArray(arr,s,mid-1);
    root->right=createArray(arr,mid+1,e);

    return root;
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;++i)cin>>arr[i];
    Node* root=createArray(arr,0,n-1);
    preorder(root);
}