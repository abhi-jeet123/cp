 
 #include<bits/stdc++.h>
 using namespace std;

class Graph{

    int V;
    list<pair<int,int>> l;
    public:
    Graph(int v){
        V=v;
    }

    void addEdge(int i,int j){
        l.push_back(make_pair(i,j));
    }

    int find(int i,int parent[]){
        if(parent[i]==-1)return i;
        
        return find(parent[i],parent);
    }

    void unionSet(int i,int j,int parent[]){
        int s1=find(i,parent);
        int s2=find(j,parent);

        if(s1!=s2){
            parent[s1]=s2;
        }

        return;


    }

    bool containsCycle(){
        int *parent=new int[V];
        for(int i=0;i<V;++i){
            parent[i]=-1;
        }

        for(auto edge:l){
            int i=edge.first;
            int j=edge.second;

            int s1=find(i,parent);
            int s2=find(j,parent);

            if(s1!=s2){
                unionSet(s1,s2,parent);
            }else{
                return true;
            }
        }
       // delete []parent;
        return false;
    }



};


 int main(){

     Graph g(4);
     g.addEdge(0,1);
     g.addEdge(1,2);
     g.addEdge(2,3);
     

     cout<<g.containsCycle()<<endl;

 }