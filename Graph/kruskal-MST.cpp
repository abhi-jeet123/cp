 
//Kruskal's Algorithm
#include<bits/stdc++.h>
using namespace std;

class Dsu{
    int *parent;
    int *rank;
    public:

        Dsu(int n){
            parent=new int[n];
            rank=new int[n];
            for(int i=0;i<n;++i){
                parent[i]=-1;
                rank[i]=1;
            }
        }

        int find(int i){
            if(parent[i]==-1)return i;
            return find(parent[i]);
        }

        void union_set(int x,int y){
            int s1=find(x);
            int s2=find(y);

            if(s1!=s2){
                if(rank[s1]<rank[s2]){
                    parent[s1]=s2;
                    rank[s2]+=rank[s1];
                }else{
                    parent[s2]=s1;
                    rank[s1]+=rank[s2];
                }
            }
            return;
        }
};

class Graph{
    vector<vector<int>> edgeList;
    int V;
    public:
        Graph(int V){
            this->V=V;
        }
        void addEdgeList(int x,int y,int w){
            edgeList.push_back({w,x,y});
        }

        int kruskalMst(){
            sort(edgeList.begin(),edgeList.end());
            int ans=0;
            Dsu s(V);
            for(auto edge:edgeList){
                int w=edge[0];
                int x=edge[1];
                int y=edge[2];
                if(s.find(x)!=s.find(y)){
                    ans+=w;
                    s.union_set(x,y);
                }
            }
            return ans;
        }
};


 int main(){
     int n,m;
	 cin>>n>>m;
	 Graph g(n);
	 for(int i=0;i<m;++i){
		 int x,y,w;
		 cin>>x>>y>>w;
		 g.addEdgeList(x-1,y-1,w);
	 }
	 cout<<g.kruskalMst()<<endl;
 }