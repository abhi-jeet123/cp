//LONGEST BITNOIC SUBSEQUENCE
#include<bits/stdc++.h>
using namespace std;

namespace Doc{
    int solve(int arr[],int n){
        int lis[n],lds[n];
        for(int i=0;i<n;++i){
            lis[i]=1;
            lds[i]=1;
        }
        for(int i=1;i<n;++i){
            for(int j=0;j<i;++j){
                if(arr[i]>arr[j] and lis[i]<lis[j]+1){
                    lis[i]=lis[j]+1;
                }
            }
        }
        for(int i=n-2;i>=0;--i){
            for(int j=n-1;j>i;--j){
                if(arr[i]>arr[j] and lds[i]<lds[j]+1){
                    lds[i]=lds[j]+1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;++i){
            if(lis[i]>1 and lds[i]>1)
            ans=max(ans,lis[i]+lds[i]-1);
        }
        return ans;
    }
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;++i)cin>>arr[i];
    cout<<Doc::solve(arr,n)<<endl;
}