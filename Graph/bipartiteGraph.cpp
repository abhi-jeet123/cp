
//Using bfs
class Solution {
public:
    

    
    bool isBipartite(vector<vector<int>>& graph) {
        int  n=graph.size();
     vector<int> color(n,0);
     queue<int> q;
     for(int i=0;i<n;++i){
         if(color[i])continue;
         q.push(i);
         color[i]=1;
         while(!q.empty()){
             int curr=q.front();
             q.pop();
             for(auto nbr:graph[curr]){
                 if(color[nbr]==0){
                     color[nbr]=-color[curr];
                     q.push(nbr);
                 }else if(color[nbr]==color[curr])return false;
             }
         }
     }
     return true;
    }
};

//using dfs

class Solution {
public:
    
    bool isBipartite(int node,vector<vector<int>> &graph,vector<int> &visited,int parent,int color){
        visited[node]=color;
        for(auto nbr:graph[node]){
            if(visited[nbr]==0){
                bool subPrb=isBipartite(nbr,graph,visited,node,3-color);
                if(subPrb==false)return false;
            }else if(nbr!=parent and color==visited[nbr]){
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n,0);
        if(isBipartite(0,graph,visited,-1,1)){
            return true;
        }return false;
    }
};

