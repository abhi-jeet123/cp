 //topological sorting

 //1.calculate the indegree
 //2.push all node with indegree =0 in queue
 //3.run a loop while queue is not empty
 //and every time we pop an node,then we udate its neighbour indegree
 //and if it comes to 0 we push it onto queue.

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
     
     
     vector<int> topoSort(){
         //calculation of indegree
         vector<int> ans;
         vector<int> indegree(V,0);
         for(int i=0;i<V;++i){
             for(auto nbr:l[i]){
                 indegree[nbr]++;
             }
         }
         queue<int> q;
         for(int i=0;i<V;++i){
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
         return ans;
     }

 };
 class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
       // if(numCourses>0 and prerequisites.size()==0)return {0};
       // if(prerequisites.size()==0)return ans;
        
        int n=prerequisites.size();
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        int count=0;
        for(int i=0;i<n;++i){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        
         queue<int> q;
         for(int i=0;i<numCourses;++i){
             if(indegree[i]==0)q.push(i);
         }
           while(!q.empty()){
             int res=q.front();
             q.pop();
             ans.push_back(res);
               ++count;
             for(auto nbr:adj[res]){
                 indegree[nbr]--;
                 if(indegree[nbr]==0)q.push(nbr);
             }
         }if(count==numCourses)
         return ans;
        else return {};
     
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
     vector<int> ans=g.topoSort();
     for(auto c:ans)cout<<c<<" ";
 }