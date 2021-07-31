#include<bits/stdc++.h>
using namespace std;

//int ans=0;

void solve(int *value,int *weight,int n,int w){
    int dp[n+1][w+1];
    int ans=0;
    for(int i=0;i<=n;++i){
        for(int j=0;j<=w;++j){
            if(i==0 or j==0)dp[i][j]=0;
            else if(value[i-1]<=j){
                dp[i][j]=max(dp[i-1][j],weight[i-1]+dp[i-1][j-value[i-1]]);
            }else dp[i][j]=dp[i-1][j];
        }
    }
    int maxFun=dp[n][w];
    for(int i=0;i<=w;++i){
        if(dp[n][i]==maxFun){ans=i;break;}
    }
    
    cout<<ans<<" "<<maxFun<<endl;
}


int main(){
    
    while(1){
        int w,n;
        cin>>w>>n;
        if(w==0 and n==0)break;
        int value[n],weight[n];
        for(int i=0;i<n;++i){
            cin>>value[i]>>weight[i];
        }
      solve(value,weight,n,w);
    }
}