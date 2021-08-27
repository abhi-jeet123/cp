

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> vec;
    for(int i=0;i<n;++i){
        int a1,a2;
        cin>>a1>>a2;
        vec.push_back(make_pair(a1,a2));
    }
    sort(vec.begin(),vec.end());
    int dp[n];
    int ans=INT_MIN;
    for(int i=0;i<n;++i)dp[i]=1;
   // memset(dp,1,sizeof(dp));
   // for(int i=0;i<n;++i)cout<<dp[i]<<" ";
    for(int i=1;i<n;++i){
        for(int j=0;j<i;++j){
            if(vec[i].first>vec[j].second and dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
                //cout<<dp[i]<<endl;
                ans=max(ans,dp[i]);
                
            }
        }
    }
    cout<<ans<<endl;
}