#include<bits/stdc++.h>
using namespace std;

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

vector<int> findUselessConnection(vector<vector<int>> edges) {
     
        int parent[100000];
        for(int i=0;i<100000;++i){
            parent[i]=-1;
        }
        vector<int> vec;
        bool flag=false;
        int x,y;

        for(auto edge:edges){
            int i=edge[0];
            int j=edge[1];

            int s1=find(i,parent);
            int s2=find(j,parent);

            if(s1!=s2){
                unionSet(s1,s2,parent);
            }else{
                flag=true;
                x=i;
                y=j;
                //vec.push_front(make_pair(i,j));
            }
        }
        vec.push_back(x);
        vec.push_back(y);
        return vec;
    
        
}