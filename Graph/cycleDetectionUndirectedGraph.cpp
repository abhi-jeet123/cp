 
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
   
     bool dfsHelper(int node,bool *visited,int parent){
         visited[node]=true;
         
         for(auto nbr:l[node]){
             if(!visited[nbr]){
                 if(dfsHelper(nbr,visited,node))return true;
                 
             }else if(nbr!=parent)return true;
         }
         return false;
     }


     bool dfs(int src,int parent){
         bool *visited=new bool[V]{0};
         if(dfsHelper(src,visited,parent))return true;
         return false;
     }

 };


 int main(){
     Graph g(6);
     g.addEdge(0,1);
     g.addEdge(1,2);
     g.addEdge(2,0);
     g.addEdge(3,4);
     g.addEdge(4,5);
     
     cout<<g.dfs(0,-1);
 }