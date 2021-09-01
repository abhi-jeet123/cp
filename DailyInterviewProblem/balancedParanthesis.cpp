


//balanced bracket problem.
#include<bits/stdc++.h>
using namespace std;

bool isMatch(char a,char b){
    if((a=='[' and b==']') or (a=='{' and b=='}') or (a=='(' and b==')'))
    return true;
    else return false;
}

int main(){
    string str;
    cin>>str;
    stack<char> s;
    bool flag=true;
    for(int i=0;i<str.size();++i){
        if(str[i]=='[' or str[i]=='{' or str[i]=='(')s.push(str[i]);
        else{
            if(isMatch(s.top(),str[i])){
                s.pop();
            }else{
                flag = false;
            }
        }
    }
    if(s.size()==0 and flag)cout<<"true"<<endl;
    else cout<<"false"<<endl;
}