#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void floodFill(vector<vector<char>>& grid,int i,int j){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size())return;
        if(grid[i][j]=='2' or grid[i][j]=='#')return;
        //not to fill visited islands and water
        grid[i][j]='2';

        floodFill(grid,i-1,j);
        floodFill(grid,i+1,j);
        floodFill(grid,i,j-1);
        floodFill(grid,i,j+1);
        
        return;
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]=='.'){
                    floodFill(grid,i,j);
                    ++cnt;
                }
            }
        }return cnt;
    }
};
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>grid[i][j];
        }
    }
    Solution s;
    cout<<s.numIslands(grid)<<endl;
    
}