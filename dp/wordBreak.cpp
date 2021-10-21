


 #include<bits/stdc++.h>
 using namespace std;


 unordered_set<string> s;


int isWordBreak(string str,int pos,vector<int> &mp){
    if(pos==str.size()){
        return true;
        //i.e we reach the end and its true
    }
    if(mp[pos]!=-1)return mp[pos];

    for(int i=pos;i<str.size();++i){
        if(s.find(str.substr(pos,i-pos+1))!=s.end() and isWordBreak(str,i+1,mp)){
            return mp[pos]=1;;
        }
    }
    mp[pos]=0;
    return false;
}

bool isWordBreakBU(string str){
    if(s.size()==0)return false;
    int n=str.size();
    vector<bool> dp(n+1,false);
    dp[0]=true;
    //dp[i]=is it possible forming word using set till i.
    for(int i=1;i<=n;++i){
        for(int j=i-1;j>=0;--j){
            if(dp[j]){
                if(s.find(str.substr(j,i-j)) != s.end() ){
                    dp[i]=true;
                    break;
                }
            }
        }
    }return dp[n];
}

 int main(){
     int n;
     cin>>n;
     string arr[n];
     vector<int> mp(n+1,-1);
    // set<string> s;
     for(int i=0;i<n;++i){
         cin>>arr[i];
         s.insert(arr[i]);
        }
     string str;
     cin>>str;
     if(isWordBreakBU(str)){
         cout<<"True"<<endl;
     }else cout<<"False"<<endl;
 }