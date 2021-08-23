// Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.  

// Insert
// Remove
// Replace

// if(s[i]==t[i]){
//    return solve(s,t,i-1,j-1);
// }else{
//    1+ min(
//        solve(s,t,i-1,j);
//        solve(s,t,i-1,j-1);
//        solve(s,t,i,j-1);
//     )
// }
#include<bits/stdc++.h>
using namespace std;

int editDistanceBottomUp(string s,string t,int n,int m){
    int dp[n+1][m+1];

    for(int i=0;i<=n;++i){
        for(int j=0;j<=m;++j){
            if(i==0)dp[i][j]=j;
            else if(j==0)dp[i][j]=i;
            else if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }else{
                dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
            }
        }
    }return dp[n][m];
}

int editDistance(string s,string t,int i,int j,vector<vector<int>> &dp){
    if(j==0)return i;
    if(i==0)return j;

    if(dp[i][j] != -1)return dp[i][j];

    if(s[i-1]==t[j-1]){
        if(dp[i-1][j-1]!=-1){
            return dp[i][j]=dp[i-1][j-1];
        }else return dp[i][j]=editDistance(s,t,i-1,j-1,dp);
    }
    else{
        int a1,a2,a3;
        if(dp[i-1][j]!=-1){
             a1=dp[i-1][j];
        }else a1=editDistance(s,t,i-1,j,dp);
        if(dp[i-1][j-1]!=-1){
            a2=dp[i-1][j-1];
        }else a2=editDistance(s,t,i-1,j-1,dp);
        if(dp[i][j-1]!=-1){
            a3=dp[i][j-1];
        }else a3=editDistance(s,t,i,j-1,dp);

        return dp[i][j]=1+min(a1,min(a2,a3));
    }

}

int main(){
    string s,t;
    cin>>s>>t;
    int n=s.size();
    int m=t.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    cout<<editDistance(s,t,n,m,dp)<<endl;
    cout<<editDistanceBottomUp(s,t,n,m)<<endl;
}
