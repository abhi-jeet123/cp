

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    multiset<int> s;
    for(int i=0;i<k;++i)s.insert(arr[i]);
    auto it=prev(s.end());
   // cout<<*it<<" ";
    int i=-1;
    int j=k-1;
    while(j<n){
        int res=arr[++i];
        int ins=arr[++j];
        it=prev(s.end());
        cout<<*it<<" ";
        it=s.find(res);
        s.erase(it);
        s.insert(ins);
    }


}