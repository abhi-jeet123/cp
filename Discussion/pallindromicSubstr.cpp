  

        //     a b c c b a
        //     0 1 2 3 4 5

        //   a b c b a
        //   0 1 2 3 4
        //   (1,3)
        //   (2,2)

        //    dp[1,4]=true;
        //    dp[2,3]=true;
        //     str[i]==str[j]{
        //         solve(i+1,j-1)true
        //         dp[i][j]=true;
        //     }


        //     (1,4)true
        //     (2,3)return true

        //            0     n-1


#include<bits/stdc++.h>
using namespace std;


int solve(string s,int i,int j,int count){

      //base case
      if(j<i)return count;

      if(i==j)return count +1;
      
       if(s[i]==s[j]){
          count = solve(s,i+1,j-1,count+2);
      }

      return max(count,max(solve(s,i+1,j,0),solve(s,i,j-1,0)));
}

int main(){
    string s;
    cin>>s;
    cout<<solve(s,0,s.size()-1,0)<<endl;
}


//bottom -up approach

a b c b a
0 1 2 3 4
  i+1,j-1
  dp[i+1][j-1]=true/false
acbba

   0  1  2  3  4  
0  t  f  f  f   t
1     t  f  t   f   
2        t  f   f
3           t   f
4               t


dp[i][j]=means that whether the substring from i to j is pallindrome or not


if(s[i]==s[j]){
    dp[i][j]=dp[i+1][j-1];
    if(dp[i+1][j-1]){
        startIndex=i;
        maxLength=(j-i+1);
    }
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
   // for(int i=0;i<n;++i)cout<<arr[i]<<" ";
    sort(arr,arr+n);
    while(q--){
        int num;
        cin>>num;
        auto it=lower_bound(arr,arr+n,num)-arr;
        cout<<n-it<<" ";


    }
}
#include<bits/stdc++.h>
#define lld long long int
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.size();
        int dp[n],arr[n];
        int cnt =0;
        for(int i=0;i<n;++i){
            if(s[i]=='R'){
                arr[i]=-1;
                ++cnt;
            }else arr[i]=1;
        }
        int maxi;
        maxi=dp[0]=arr[0];
        for(int i=1;i<n;++i){
            dp[i]=max(arr[i],arr[i]+dp[i-1]);
            maxi=max(maxi,dp[i]);
        }cout<<maxi+cnt<<endl;
    }
}