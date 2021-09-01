

#include<bits/stdc++.h>
#define lld long long int
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<lld> arr(n);
    for(int i=0;i<n;++i)cin>>arr[i];
    vector<lld> dp1(n,0);
    vector<lld> dp2(n,0);
    dp2[0]=arr[0];
    dp2[1]=arr[1]+arr[0];
   // else dp2[1]=arr[1];
    for(int i=0;i<n;++i){
        if(i<k)dp1[i]=0;
        else if(i==k)dp1[i]=arr[i];
        else dp1[i]=arr[i]+max(dp1[i-1],dp1[i-2]);
    }
    for(int i=2;i<n;++i)dp2[i]=arr[i]+max(dp2[i-1],dp2[i-2]);
    lld ans=INT_MIN;
    for(int i=k-1;i<n;++i){
        ans=max(ans,dp1[i]+dp2[i]-arr[i]);
    }
    //for(int i=0;i<n;++i)cout<<dp1[i]<<" ";
   // cout<<endl;
   // for(int i=0;i<n;++i)cout<<dp2[i]<<" ";
    cout<<ans<<endl;
    
}