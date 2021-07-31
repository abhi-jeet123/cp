#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int matrix[n][m];
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>matrix[i][j];
        }
    }
    int dp[n][m];
    for(int i=0;i<m;++i)dp[0][i]=matrix[0][i];

    for(int i=1;i<n;++i){
        for(int j=0;j<m;++j){
            if(j==0)dp[i][j]=matrix[i][j]+min(dp[i-1][j],dp[i-1][j+1]);
            else if(j==m-1)dp[i][j]=matrix[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
            else dp[i][j]=matrix[i][j]+min(dp[i-1][j],min(dp[i-1][j-1],dp[i-1][j+1]));
        }
    }int ans=INT_MAX;
    for(int i=0;i<m;++i){
        ans=min(ans,dp[n-1][i]);
    }
    cout<<ans<<endl;
}