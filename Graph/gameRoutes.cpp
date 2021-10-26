 #include<bits/stdc++.h>
 #define mod 1000000007
 using namespace std;

const int N = 1e5 + 5;
vector <int> Graph[N];

 int topoSort(int src,int n){
     vector<int> indegree(n,0);
     for(int i=1;i<n;++i){
         for(auto it:Graph[i]){
             indegree[it]++;
         }
     }
     queue<int> q;
     for(int i=1;i<n;++i){
         if(indegree[i]==0)q.push(i);
     }
     vector<int> res;
     while(!q.empty()){
         int curr=q.front();
         res.push_back(curr);
         q.pop();
         for(auto nbr:Graph[curr]){
             indegree[nbr]--;
             if(indegree[nbr]==0)q.push(nbr);
         }
     }
    
     vector<int> dp(n,0);
     dp[src]=1;
     



     for(auto node:res){
         for(auto it:Graph[node]){
             //cout<<it<<" ";
             dp[it]=(dp[it]+dp[node])%mod;
             //cout<<dp[it]<<"->"<<it<<" ";

         }
     }
     //for(auto c:dp)cout<<c<<" ";
     return dp[n-1];
 }
 
 int main(){
     int n,m;
     cin>>n>>m;
     //vector<int> Graph[n+1];
     for(int i=0;i<m;++i){
         int u,v;
         cin>>u>>v;
         Graph[u].push_back(v);
     }
    //  for(int i=1;i<=n;++i){
    //      for(auto nbr:Graph[i]){
    //          cout<<nbr<<" ";
    //      }cout<<endl;
    //  }
     cout<<topoSort(1,n+1)<<endl;
 }