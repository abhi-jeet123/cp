
//detect cycle in 2d-grid 
class Solution {
public:
    
    
    bool dfs_helper(int i,int j,int prev_i,int prev_j,vector<vector<char>> &grid,vector<vector<bool>> &visited,char &ch){
    if(i>=grid.size() or i<0 or j<0 or j>=grid[0].size()){
        return false;
    }
    if(visited[i][j]==true)return true;
    visited[i][j]=true;
    bool a1=false,a2=false,a3=false,a4=false;
    if(i+1<grid.size() and i+1 != prev_i and grid[i+1][j]==ch){
        a1=dfs_helper(i+1,j,i,j,grid,visited,ch);
    }
    if(i-1>=0 and i-1 != prev_i and grid[i-1][j]==ch){
        a2=dfs_helper(i-1,j,i,j,grid,visited,ch);
    }
    if(j+1<grid[0].size() and j+1 != prev_j and grid[i][j+1]==ch){
        a3=dfs_helper(i,j+1,i,j,grid,visited,ch);
    }
    if(j-1>=0 and j-1 != prev_j and grid[i][j-1]==ch){
        a4=dfs_helper(i,j-1,i,j,grid,visited,ch);
    }

    return (a1 || a2 || a3 || a4);

}
    
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool> (m,false));
        bool ans=false;
        for(int i=0;i<grid.size();++i){
         for(int j=0;j<grid[0].size();++j){
             if(!visited[i][j]){
                 // visited[i][j]=true;
                  ans=ans || dfs_helper(i,j,-1,-1,grid,visited,grid[i][j]);
                  if(ans==true)return ans;
             }
         }
     }return ans;}
};