


#include<bits/stdc++.h>
#define lld long long int
using namespace std;
int main(){
    int t;
    cin>>t;
    int test=1;
    while(t--){
        //int test=1;
        lld n;
        cin>>n;
        string s;
        cin>>s;
        lld left[n],right[n];
        if(s[0]=='1')left[0]=1;
        else left[0]=INT_MAX;
        for(int i=1;i<n;++i){
            if(s[i]=='1'){
                left[i]=i+1;
            }else left[i]=left[i-1];
        }
        if(s[n-1]=='1')right[n-1]=n;
        else right[n-1]=INT_MAX;
        for(int j=n-2;j>=0;--j){
            if(s[j]=='1'){
                right[j]=j+1;
            }else right[j]=right[j+1];
        }
        lld ans=0;
        for(int i=0;i<n;++i){
            int temp1=abs(i+1-left[i]);
            int temp2=abs(i+1-right[i]);
            ans+=min(temp1,temp2);
        }
        cout<<"Case #"<<test<<":"<<" ";
        cout<<ans<<endl;
        ++test;
    }
}