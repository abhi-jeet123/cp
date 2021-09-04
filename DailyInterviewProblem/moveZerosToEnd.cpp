

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i)cin>>arr[i];
    int left=0,right=0;
    while(right<n){
        if(arr[right]!=0){
            swap(arr[left],arr[right]);
            right++;
            ++left;
            continue;
        }
        ++right;
    }
    for(int i=0;i<n;++i)cout<<arr[i]<<" ";
}