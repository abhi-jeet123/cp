#include<bits/stdc++.h>
using namespace std;


int find(int i,int parent[]){
    if(parent[i]==-1)return i;
    return find(parent[i],parent);
}

void unionSet(int i,int j,int parent[]){
    int s1=find(i,parent);
    int s2=find(j,parent);
    
    if(s1!=s2)parent[s1]=s2;
    return;
}

vector<bool> DSU(vector<vector<int>>query)
{   vector<bool> vec;
    int parent[100000];
    for(int i=0;i<100000;++i){
        parent[i]=-1;
    }
    for(auto edge:query){
        if(edge[0]==1){
            unionSet(edge[1],edge[2],parent);
        }else{
            int s1=find(edge[1],parent);
            int s2=find(edge[2],parent);
            if(s1==s2)vec.push_back(true);
            else vec.push_back(false);
        }
        
    }return vec;
}