 //Prims's-Minimum Spanning tree

 #include<bits/stdc++.h>
 using namespace std;

class Graph{
	vector<pair<int,int>> *l;
	int V;
	public:
	Graph(int v){
		this->V=v;
		l=new vector<pair<int,int>>[v];
	}

	void addEdge(int x,int y,int w){
		l[x].push_back({y,w});
		l[y].push_back({x,w});
	}

	int mstPrims(){
		priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> q;
		int ans=0;
		bool *visited=new bool[V]{0};
		q.push({0,0});
		while(!q.empty()){
			auto best=q.top();
			q.pop();
			int to=best.second;
			int weight=best.first;
			if(visited[to]){
				continue;
				//discard the dge and continue
			}
			ans+=weight;
			visited[to]=true;
			for(auto x:l[to]){
				if(visited[x.first]==0){
					q.push({x.second,x.first});
				}
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
		 g.addEdge(x-1,y-1,w);
	 }
	 cout<<g.mstPrims()<<endl;
 }