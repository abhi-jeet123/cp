


bool isPresent(node* root,int target){
    stack<node*> s1;
    stack<node*> s2;

    bool done1=false,done2=false;
    int val1,val2;
    node* curr=root;
    node* temp=root;
    while(1){
        while(done1==false){
            if(curr!=NULL){
                s1.push(curr);
                curr=curr->left;
            }else {
                if(!s1.empty()){
                    done1=true;
                }else{
                    curr=s1.pop();
                    val1=curr->Val;
                    curr=curr->right;
                    done1=true;
                }
            }
        }
        while(done2==false){
            if(temp!=NULL){
                s2.push(temp);
                temp=temp->right;
            }else{
                if(!s2.empty()){
                    done2=true;
                }else{
                    temp=s2.pop();
                    val2=temp->val;
                    temp=temp->left;
                    done2=true;
                }
            }
        }

        if(val1 != val2 and val1+val==target){
            return true;
        }else if(val1+val2<target){
            done1=false;
        }else if(val1+val2>target){
            done2=false;
        }else if(val1>val2)return false;
    }
    return false;
}