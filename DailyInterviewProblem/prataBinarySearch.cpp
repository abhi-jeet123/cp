#include<bits/stdc++.h>
using namespace std;
bool isPossible(int arr[],int n,int mid,int prata){
	int cnt = 0;
	for(int i = 0;i<n;++i){
		int t = arr[i];
		int j = 2;
		while( t <= mid){
			
			 ++cnt;
			 
			 t += (j*arr[i]);
			 ++j;
			 
		}if(cnt >= prata)return true;
		
	}return false;
}
 
int minTime(int arr[],int n,int prata){
	int s = 0;
	int e = 100000007;
	int mid , ans = INT_MAX;
	
	while(s <= e ){
		mid = s+(e-s)/2;
		if(isPossible(arr,n,mid,prata)){
			ans = min(ans,mid);
			e = mid - 1;
		}else s = mid + 1;
	}return ans;
}
 
 
int main(){
	int t;
	cin>>t;
	while(t--){
		int prata;
		cin>>prata;
		int n;
		cin>>n;
		int arr[n];
		for(int i = 0 ; i < n ; ++i){
			cin>>arr[i];
		}
		cout<<minTime(arr,n,prata)<<endl;
	}
} 
