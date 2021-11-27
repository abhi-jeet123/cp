#include <bits/stdc++.h>
using namespace std;


int uniqueBinaryTree(int n){
    int dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;++i){
        for(int j=0;j<i;++j){
            dp[i]+=(dp[j]*dp[i-j-1]);
        }
    }return dp[n];
}

int main(){
    int n;
    cin>>n;
    cout<<uniqueBinaryTree(n)<<endl;
}
#include<bits/stdc++.h>
#define lld long long int
using namespace std;

void updateArray(int l,int r,int *arr,int n){
    arr[l]+=1;
    if(r!=n)arr[r]-=1;
    return;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    memset(arr,0,sizeof(arr));
    int r;
    cin>>r;
    while(r--){
        int l,r;
        cin>>l>>r;
        l-=1;
        updateArray(l,r,arr,n);
    }
    int q;
    cin>>q;
    for(int i=1;i<n;++i)arr[i]+=arr[i-1];
    for(int i=0;i<n;++i)cout<<arr[i]<<" ";
    while(q--){
        int num=0;

    }
}


#include <bits/stdc++.h>
using namespace std;
int main() {
    string str;
    getline(cin,str);
    str=str+" ";
    string word="";
    vector<string> vec;
    map<string,int> mp;
    for(int i=0;i<str.size();++i){
        if(str[i]==' '){
            mp[word]++;
            word="";
        }
        else word+=str[i];
    }
    for(auto c:mp){
        if(c.second>1)vec.push_back(c.first);
    }
    sort(vec.begin(),vec.end());
    for(auto c:vec)cout<<c<<" ";
    
}
