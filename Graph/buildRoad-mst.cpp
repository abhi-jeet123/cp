#include<bits/stdc++.h>
using namespace std;

class Graph{
	vector<pair<long long,long long>> *l;
	long long V;
	public:
	Graph(long long v){
		this->V=v;
		l=new vector<pair<long long,long long>>[v];
	}

	void addEdge(long long x,long long y,long long w){
		l[x].push_back({y,w});
		l[y].push_back({x,w});
	}

	long long mstPrims(){
		priority_queue<pair<long long,long long>, vector<pair<long long,long long>>,greater<pair<long long,long long>>> q;
		long long ans=0;
		bool *visited=new bool[V]{0};
		q.push({0,0});
		while(!q.empty()){
			auto best=q.top();
			q.pop();
			long long to=best.second;
			long long weight=best.first;
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

long long buildRoads(vector<vector<long long>>Coordinates){
    long long n=Coordinates.size();
        Graph g(n);
        for(long long i=0;i<n-1;++i){
            for(long long j=i+1;j<n;++j){
                long long w=min(abs(Coordinates[i][0]-Coordinates[j][0]),abs(Coordinates[i][1]-Coordinates[j][1]));
                long long x=i;
                long long y=j;
                g.addEdge(x,y,w);
                
            }
        }
        return g.mstPrims();
    
}