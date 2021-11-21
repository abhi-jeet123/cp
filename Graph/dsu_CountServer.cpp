class DSU {
public:
    vector<int> parent;
    DSU(int n) {
        for (int i = 0; i < n; i++)
            parent.push_back(i);
    }
    int find(int i) {
        if (parent[i] != i)
            parent[i] = find(parent[i]);
        return parent[i];
    }
    void unionSet(int i, int j) {
        parent[find(j)] = find(i);
    }
};



class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        DSU my_dsu(m*n);
        for(int i=0;i<m;++i){
            int j=0;
            for(;j<n and grid[i][j]==0;++j);
            for(int k=j+1;k<n;++k){
                if(grid[i][j]){
                    my_dsu.unionSet(i*n+j,i*n+k);
                }
            }
        }
        for(int j=0;j<n;++j){
            int i=0;
            for(;i<m and grid[i][j]==0;++i);
            for(int k=i+1;k<m;++k){
                if(grid[k][j]){
                    my_dsu.unionSet(i * n + j, k * n + j);
                }
            }
        }
        unordered_map<int,int> mp;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j] and my_dsu.find(i*n+j)!=i*n+j){
                    mp[my_dsu.find(i*n+j)]++;
                }
            }
        }
        int res=0;
        for(auto it:mp){
            res+=it.second+1;
        }
        return res;
    }
};