 
 //BFS traversal of graph

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
     void bfs(int src){
         bool *vis=new bool[V]{0};
         queue<int> q;
         q.push(src);
         vis[src]=true;
         while(!q.empty()){
             int curr=q.front();
             q.pop();
             cout<<curr<<" ";
             for(auto nbr:l[curr]){
                 if(!vis[nbr]){
                     q.push(nbr);
                     vis[nbr]=true;
                 }
             }
         }
         return;
     }
 };

 int main(){
     Graph g(7);
     g.addEdge(0,1);
     g.addEdge(1,2);
     g.addEdge(2,3);
     g.addEdge(3,5);
     g.addEdge(5,6);
     g.addEdge(4,5);
     g.addEdge(0,4);
     g.addEdge(3,4);
     g.bfs(1);
 }