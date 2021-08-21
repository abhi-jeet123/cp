#include<bits/stdc++.h>
using namespace std;
int main(){
  
int t;
cin>>t;
while(t--){

    int n;
    cin>>n;
    int arr[n],brr[n],crr[n];
    for(int i=0;i<n;++i){
        cin>>arr[i];
        brr[i]=arr[i];
        crr[i]=arr[i];
    }
    sort(brr,brr+n);


    for(int i=0;i<n-2;++i){
    int p=arr[i];
    int q=arr[i+1];
    int r=arr[i+2];
    if(p+r>q and p>r){
        swap(arr[i],arr[i+2]);
    }
}
bool flag1=true;
bool flag2=true;
for(int i=0;i<n;++i){
    if(arr[i]!=brr[i])flag1=false;
}
for(int i=n-1;i>1;--i){
    int p=crr[i];
    int q=crr[i-1];
    int r=crr[i-2];
    if(p+r>q and p<r){
        swap(crr[i],crr[i-2]);
    }
}
for(int i=0;i<n;++i){
    if(crr[i]!=brr[i])flag2=false;
}
if(flag1 or flag2)cout<<"YES"<<endl;
else cout<<"NO"<<endl;




}



               
    
}
