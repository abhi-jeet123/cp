//IN Network Delay Time question:
//You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

//We will send a signal from a given node k. Return the time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.
//So what we can do is we can the minimum time required to reach each node from the
//given source node,but here edges are directed
//so we will just change our addedge function and it will work for directed edges also
//and at last we will take the maximum of every node whose value we intialized.


class Graph{
    list<pair<int,int>> *l;
	int V;

public:
	Graph(int v){
		V=v;
		l=new list<pair<int,int>>[V];
	}
	void addEdge(int x,int y,int wt){
		l[x].push_back({wt,y});
		//l[y].push_back({wt,x});
		return;
	}
    int dijkstras(int src){
         vector<int> dist(V,INT_MAX);
		 set<pair<int,int>> s;
		 dist[src]=0;
		 s.insert({0,src});
		 //first part will contain weight and second node,so that we can always run greedy
		 //by find the least distance covered node.
		 while(!s.empty()){

			 auto it=s.begin();
			 int node=it->second;
			 int distTillNow=it->first;
			 s.erase(it);

			 for(auto nbrPair:l[node]){
                 
				 int nbr=nbrPair.second;
				 int edgeWeight=nbrPair.first;


				 if(distTillNow + edgeWeight < dist[nbr]){
					 auto itr=s.find({dist[nbr],nbr});
					 if(itr!=s.end()){
						 
						 s.erase(itr);
					 }
					 dist[nbr]=distTillNow + edgeWeight;
					 s.insert({dist[nbr],nbr});
				 }
			 }
			 
		 }
		 //cout<<"hello"<<endl;
        int ans=0;
        bool flag=true;
        for(auto c:dist){
            cout<<c<<" ";
            if(c!=INT_MAX)
            ans=max(ans,c);
            else flag=false;
        }
        if(flag)
        return ans;
        else return -1;
		 
	}
};



class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        Graph g(n);
        for(auto edge:times){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            g.addEdge(u-1,v-1,w);
            
        }
        int ans=g.dijkstras(k-1);
        return (ans==0)?-1:ans;
        
    }
};