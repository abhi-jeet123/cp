



// remove kth node from end of linked kist
// first we traverse the linked list and calculate the lenth of linked list,
// then we print n-k from begining

node* deleteK(node *head,int k){
    if(head==NULL)return head;
    int n=0;
    for(node *temp=head;temp->next!=NULL;temp=temp->next)++n;
    int res=n-k;
    node*curr=head;
    for(int i=0;i<res-1;++i)curr=curr->next;
    curr->next=curr->next->next;
    return head;
}

//now a single pass approach
//we will use to node pointer and move one pointer to k steps,then move both 
//together as soon as fast pointer reaches the end node,our slow pointer next point to"kth node from end of linked list".

node *deleteK(node *head,int k){
    if(head==NULL)return head;
    node*slow=head;
    node*fast=head;
    for(int i=0;i<k;++k){
        fast=fast->next;
    }
    while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=slow->next->next;
    return head;
}