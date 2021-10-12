 
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
             cout<<curr<<" ";
             for(auto nbr:l[curr]){
                 if(!vis[nbr]){
                     q.push(nbr);
                     vis[nbr]=true;
                     parent[nbr]=curr;
                     dist[nbr]=dist[curr]+1;
                 }
             }
         }cout<<endl;
         for(int i=0;i<V;++i){
             cout<<"shortest distance of node "<<i<<" from source is "<<dist[i]<<endl;
         }
         if(dest!=-1){
             int temp=dest;
             while(temp!=src){
                 cout<<temp<<"-->";
                 temp=parent[temp];
             }
             cout<<src<<endl;
         }
         return;
     }

 };

 int minDiceThrow(int n,vector<pair<int,int>> snake,vector<pair<int,int>> ladder){
         vector<int> board(n+1,0);
         //to know the the increment or decrement from that position ,because of 
         //ladders and snake.
         for(auto c:snake){
             int s=c.first;
             int e=c.second;
             board[s]=e-s;
         }
         for(auto lp:ladder){
             int s=lp.first;
             int e=lp.second;
             board[s]=e-s;
         }
         Graph g(n+1);
         for(int u=1;u<n;++u){
             for(int dice=1;dice<=6;++dice){
                 int v=u+dice;
                 v+=board[u];
                 g.addEdge(u,v);
             }
         }
         return 0;
         //now call the bfs using the above graph formed and pass src and dest as 
         //end index and get the min distance
         
     }

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
     g.bfs(1,6);
 }