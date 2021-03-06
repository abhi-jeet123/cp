 //Detect cycle in directed graph
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
         
     }

     void dfs_helper(int node,vector<bool> &visited,list<int> &ordering){
         visited[node]=true;
         for(auto nbr:l[node]){
             if(!visited[nbr]){
                 dfs_helper(nbr,visited,ordering);
             }
         }
         ordering.push_front(node);
         return;
     }

     void topoSortDFS(){
         list<int> ordering;
         vector<bool> visited(V,false);
         for(int i=0;i<V;++i){
             if(!visited[i]){
                 dfs_helper(i,visited,ordering);
             }
         }
         for(auto c:ordering)cout<<c<<" ";
         return;
     }
};

int main(){
    Graph g(6);
     g.addEdge(0,2);
     g.addEdge(2,3);
     g.addEdge(3,5);
     g.addEdge(4,5);
     g.addEdge(1,4);
     g.addEdge(1,2);
     g.topoSortDFS();
}