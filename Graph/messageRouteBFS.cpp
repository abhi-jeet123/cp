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
     void bfs(int src,int dest){
         bool *vis=new bool[V]{0};
         int *dist=new int[V]{0};
         int *parent=new int[V]{0};

         queue<int> q;
         q.push(src);
         vis[src]=true;
         dist[src]=0;
         parent[src]=-1;
         while(!q.empty()){
             int curr=q.front();
             q.pop();
             //cout<<curr<<" ";
             for(auto nbr:l[curr]){
                 if(!vis[nbr]){
                     q.push(nbr);
                     vis[nbr]=true;
                     parent[nbr]=curr;
                     dist[nbr]=dist[curr]+1;
                 }
             }
         }
         vector<int> vec;
         
         if(dist[dest]!=0){
             cout<<dist[dest]+1<<endl;
             int temp=dest;
             while(temp!=src){
                 vec.push_back(temp);
                 temp=parent[temp];
             }
             vec.push_back(src);
             reverse(vec.begin(),vec.end());
             for(auto c:vec)cout<<c<<" ";
         }else cout<<"IMPOSSIBLE"<<endl;
         
         return;
     }
     

 };

int main()
{
    int n,m;
    cin>>n>>m;
    Graph g(n+1);
    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }
    g.bfs(1,n);
    return 0;
    
}