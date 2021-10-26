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
     void topoSort(int src){
         //calculation of indegree
         vector<int> ans;
         vector<int> indegree(V,0);
         for(int i=1;i<V;++i){
             for(auto nbr:l[i]){
                 indegree[nbr]++;
             }
         }
         queue<int> q;
         for(int i=1;i<V;++i){
             if(indegree[i]==0)q.push(i);
         }
         while(!q.empty()){
             int res=q.front();
             q.pop();
             ans.push_back(res);
             for(auto nbr:l[res]){
                 indegree[nbr]--;
                 if(indegree[nbr]==0)q.push(nbr);
             }
         }
         vector<int> dist(V,INT_MIN);
         vector<int> parent(V,0);
         dist[src]=0;
         parent[src]=1;
         for(auto node:ans){
             for(auto nbr:l[node]){
                 if(node!=INT_MIN){
                     if(dist[nbr]<dist[node]+1){
                         dist[nbr]=dist[node]+1;
                         parent[nbr]=node;
                     }
                 }
             }
         }
         if(dist[V-1]<0){
             cout<<"IMPOSSIBLE"<<endl;
             return;
         }
         cout<<dist[V-1]+1<<endl;
         vector<int> pr;
         for(int i=V-1;i!=src;i=parent[i]){
             pr.push_back(i);
         }pr.push_back(src);
         reverse(pr.begin(),pr.end());
         for(auto c:pr)cout<<c<<" ";
         cout<<endl;
         
         return;
     }

};

int main(){
    int n,m;
    cin>>n>>m;
    Graph g(n+1);
    for(int i=0;i<m;++i){
        int l,r;
        cin>>l>>r;

        g.addEdge(l,r);
    }
    g.topoSort(1);
    
}