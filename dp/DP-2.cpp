#include<bits/stdc++.h>
using namespace std;

int dp[101][101][101];

bool lcs(string s,string t,int k){
    int n=s.size();
    int m=t.size();
    int dp[n+1][m+1];
    for(int i=0;i<=n;++i){
        for(int j=0;j<=m;++j){
            if(i==0 or j==0)dp[i][j]=0;
            else if(s[i-1]==t[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int len=dp[n][m];

    if(len<k)return false;
    return true;
    

}

int recurLcs(string s,string t,int i,int j,int l){
    if(l==0)return 0;
    if(i<0 or j<0)return INT_MIN;

    if(dp[i][j][l] != -1){
        return dp[i][j][l];
    }
    if(s[i]==t[j]){
         dp[i][j][l]=max(recurLcs(s,t,i-1,j-1,l),recurLcs(s,t,i-1,j-1,l-1)+int(s[i]));
    }else{
         dp[i][j][l] =max(recurLcs(s,t,i-1,j,l),recurLcs(s,t,i,j-1,l));
    }
    return dp[i][j][l];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s,t;
        cin>>s;
        cin>>t;
        int k;
        cin>>k;
        memset(dp,-1,sizeof(dp));
        bool flag=lcs(s,t,k);
        if(flag)
        cout<<recurLcs(s,t,s.size()-1,t.size()-1,k)<<endl;
        else cout<<"0"<<endl;
    }
}