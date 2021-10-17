
//Course schedule problem: we just have to find that there is any cycle present
//in directed graph or not,if present than it is difficult to complete course
//else return true.

class Solution {
    //int V;
public:
 
 bool isCycle(vector<vector<int>> &graph,vector<bool> &visited,int node,vector<bool> &st){
         visited[node]=true;
         st[node]=true;//call stack entry;

         for(auto nbr:graph[node]){
             if(st[nbr]==true){
                 return true;
             }else if(visited[nbr]==false){
                 if(isCycle(graph,visited,nbr,st)){
                     return true;
                 }
             }
         }

         //while going back stack[node] must be set to false
         st[node]=false;
         return false;
     }

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses, false);
        vector<bool> st(numCourses,false);
        vector<vector<int>> graph(numCourses);
        
        // build graph
        for (auto pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (isCycle(graph, visited, i,st)) return false;
            }
            
        }
        return true;
    }
};