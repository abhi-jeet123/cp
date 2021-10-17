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


     bool dfs_helper(int node,vector<bool> &visited,vector<bool> &stack){
         visited[node]=true;
         stack[node]=true;//call stack entry;

         for(auto nbr:l[node]){
             if(stack[nbr]==true){
                 return true;
             }else if(visited[nbr]==false){
                 if(dfs_helper(nbr,visited,stack)){
                     return true;
                 }
             }
         }

         //while going back stack[node] must be set to false
         stack[node]=false;
         return false;
     }


     //wrapper function
     bool containesCycle(){
         vector<bool> visited(V,false);
         vector<bool> stack(V,false);

         for(int i=0;i<V;++i){
             int src=i;
             if(!visited[src]){
                 if(dfs_helper(src,visited,stack)){
                     return true;
                 }
             }
         }return false;
     }
   
     

 };


 int main(){
     Graph g(3);
     g.addEdge(0,1);
     g.addEdge(1,2);
     g.addEdge(2,0);
     
     
     cout<<g.containesCycle();
 }