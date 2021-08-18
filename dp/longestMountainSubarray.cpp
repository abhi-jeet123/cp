//LONGEST MOUNTAIN SUBARRAY
#include<bits/stdc++.h>
using namespace std;


    int solve(int arr[],int n){
        int lis[n],lds[n];
        for(int i=0;i<n;++i){
            lis[i]=0;
            lds[i]=0;
        }
        for(int i=1;i<n;++i){
                if(arr[i]>arr[i-1] and lis[i]<lis[i-1]+1){
                    lis[i]=lis[i-1]+1;
                }
            }
        for(int i=n-2;i>=0;--i){
                if(arr[i]>arr[i+1] and lds[i]<lds[i+1]+1){
                    lds[i]=lds[i+1]+1;
                }
            }
        
        int ans=0;
        for(int i=0;i<n;++i){
            if(lis[i]>0 and lds[i]>0)
            ans=max(ans,lis[i]+lds[i]+1);
        }
        if(ans>=3)
        return ans;
        else return 0;
    }


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;++i)cin>>arr[i];
    cout<<solve(arr,n)<<endl;
}