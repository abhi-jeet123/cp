


#include<bits/stdc++.h>
using namespace std;

//here we are gona use 2 dp.
//if we ignore the circular array case,then our solution is simple
//at ecery step we just include cureent element and get the minimum from rest previous solved
//dp[i]=arr[i]+min(dp[i-1],dp[i-2]);
//since this is circular case and in every adjacent element one element must bhi included
//in our above solution we calculated or ans for An (i.e it is sure that we have considered nth element as in our calulation we are considering current element)but what about A1
//so to for A1 includation we will backward fill the dp array and get the result
//ans ans will be min(fdp[n-1],bdp[0]);
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i)cin>>arr[i];
    vector<int> fdp(n,0);
    vector<int> bdp(n,0);
    fdp[0]=arr[0];
    fdp[1]=arr[1];
    bdp[n-1]=arr[n-1];
    bdp[n-2]=arr[n-2];
    for(int i=2;i<n;++i)fdp[i]=arr[i]+min(fdp[i-1],fdp[i-2]);
    for(int i=n-3;i>=0;--i)bdp[i]=arr[i]+min(bdp[i+1],bdp[i+2]);
    int ans=min(fdp[n-1],bdp[0]);
    cout<<ans<<endl;

}