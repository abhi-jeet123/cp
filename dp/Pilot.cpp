#include<bits/stdc++.h>
#define lld long long int
using namespace std;

lld dp[10005][5005];

struct Node{
	lld cap,ast;
};

lld solve( Node *arr,int n,lld idx,lld captain,lld assistance){
	if(dp[idx][assistance] != -1)return dp[idx][assistance];
	
	if(idx==n)return 0;
	
	if(assistance==n/2){
		return dp[idx][assistance]=arr[idx].cap+solve(arr,n,idx+1,captain+1,assistance);
		//i.e all assistance are appointed now only captaibs are neended;
	}
	else if(assistance == captain){
		return dp[idx][assistance]=arr[idx].ast+solve(arr,n,idx+1,captain,assistance+1);
		//when both are in equal quantity it is best to choose the assiatnce first as we can not choose the assistance with higher experience with that of captain,since we are going uppward in arry.
		
	}
	else{
		return dp[idx][assistance]=min(arr[idx].cap+solve(arr,n,idx+1,captain+1,assistance),arr[idx].ast+solve(arr,n,idx+1,captain,assistance+1));
	}
}

int main(){
	int n;
	cin>>n;
	Node arr[n];
	for(int i=0;i<n;++i){
		cin>>arr[i].cap>>arr[i].ast;
	}
	memset(dp,-1,sizeof(dp));
	lld ans=arr[0].ast+solve(arr,n,1,0,1);
	cout<<ans<<endl;
}