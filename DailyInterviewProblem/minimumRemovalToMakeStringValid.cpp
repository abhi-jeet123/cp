

//minimum removal to make paranthesis valid

#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    int cnt=0;
    stack<int> s;
    for(int i=0;i<str.size();++i){
        if(str[i]=='(')s.push(str[i]);
        else{
            if(!s.empty())s.pop();
            else ++cnt;
        }
    }
    while(!s.empty()){
        s.pop();
        ++cnt;
    }
    cout<<cnt<<endl;
}