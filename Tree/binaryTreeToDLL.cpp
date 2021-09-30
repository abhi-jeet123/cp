


//convert binary tree doubly linked list
#include<bits/stdc++.h>
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

void binaryTreeToDLL(node *root,node **head){
    if(root==NULL)return ;

    static node*prev=NULL;
    binaryTreeToDLL(root->left,head);

    if(prev==NULL)*head=root;
    else{
        root->left=prev;
        prev->right=root;
    }
    prev=root;

    binaryTreeToDLL(root->right,head);
}

void printList(node *node)
{
    while (node!=NULL)
    {
        cout << node->val << " ";
        node = node->right;
    }

}//10 12 25 -1 -1 30 -1 -1 15 36 -1 -1 -1
int main(){
    node *root=build_btree();
    node *head=NULL;
    binaryTreeToDLL(root,&head);
    printList(head);
    return 0;
}