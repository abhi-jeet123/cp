


#include<bits/stdc++.h>
using namespace std;
//dp[i]=max amount of money he can achieve from i teams
//there could be two case for these type of problem
//either we include them or exclude them
//1.when we exclude it then---dp[i]=dp[i-1](we will not include the current item and we will take best answer till i-1)
//2.when we include the current item,then there could be two case
//a)we will take current item and pic best answer from dp[i-2](becuse we cannot select 3 row and including dp[i-1] may cause this uncertain)
//arr[i]+dp[i-2]
//b)arr[i]+arr[i-1]+dp[i-3],taking current and previous and excluding the 3rd element,and taking best from dp[i-3] for it
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;++i)cin>>arr[i];
    vector<int> dp(n,0);
    dp[0]=arr[0];
    dp[1]=dp[0]+arr[1];
    dp[2]=max(dp[1],max(arr[2]+arr[1],arr[2]+dp[0]));
   // cout<<dp[0]<<" "<<dp[1]<<" "<<dp[2]<<endl;
    for(int i=3;i<n;++i){
        dp[i]=max(dp[i-1],max(arr[i]+dp[i-2],arr[i]+arr[i-1]+dp[i-3]));
        
    }
    cout<<dp[n-1]<<endl;
}