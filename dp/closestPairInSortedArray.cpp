#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr1(n);
    vector<int> arr2(n);
    for(int i=0;i<n;++i)cin>>arr1[i];
    for(int i=0;i<n;++i)cin>>arr2[i];
    int k;
    cin>>k;
    pair<int,int> p;
    int abslt=INT_MAX;
    for(int i=0;i<n;++i){
        int temp=arr2[i];
        int res=k-temp;
        auto it=lower_bound(arr1.begin(),arr1.end(),res);
        
        int index=it-arr1.begin();
        if(index>=n)index=n-1;
        
        temp=arr2[i]+arr1[index];
        int diff=abs(k-temp);
        if(diff<abslt){
           p.first=arr2[i];
           p.second=arr1[index];
           abslt=diff;
        }
        
        if(index>0){
            temp=arr2[i]+arr1[index-1];
            diff=abs(k-temp);
            if(diff<abslt){
                p.first=arr2[i];
                p.second=arr1[index-1];
                abslt=diff;
            }
        }

    
    }
    cout<<p.first<<" "<<p.second;
}