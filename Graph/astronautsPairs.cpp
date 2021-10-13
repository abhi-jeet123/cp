#include<bits/stdc++.h>
using namespace std;

class Graph{
     int V;
     list<int> *l;

     public:
     Graph(int v){
         V=v;
         l=new list<int>[v];
     }
     void addEdge(int i,int j){
         l[i].push_back(j);
         l[j].push_back(i);
     }
    
     void dfsHelper(int node,bool *visited,int &cnt){
         visited[node]=true;
         ++cnt;
         for(auto nbr:l[node]){
             if(!visited[nbr]){
                 dfsHelper(nbr,visited,cnt);
             }
         }
         return;
     }


     void dfs(int n){
         bool *visited=new bool[V]{0};
         int cnt=0;
         vector<int> ans;
         for(int i=0;i<n;++i){
             if(!visited[i]){
                 dfsHelper(i,visited,cnt);
                 ans.push_back(cnt);
                 cnt=0;
             }
         }
         int res=n*(n-1)/2;
         for(auto c:ans){
             res-=c*(c-1)/2;
         }
         cout<<res<<" ";
         return;
     }

 };

int main(){

    int n,m;
    cin>>n>>m;
    Graph g(n);
    while(m--){
        int i,j;
        cin>>i>>j;
        g.addEdge(i,j);
    }
    g.dfs(n);
    
}