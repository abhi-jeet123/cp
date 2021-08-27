class Solution {
public:
    
    void floodFill(vector<vector<int>>& grid,int i,int j,int &cnt){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size())return;
        if(grid[i][j]==2 or grid[i][j]==0)return;
        //not to fill visited islands and water
        grid[i][j]=2;
        ++cnt;

        floodFill(grid,i-1,j,cnt);
        floodFill(grid,i+1,j,cnt);
        floodFill(grid,i,j-1,cnt);
        floodFill(grid,i,j+1,cnt);
        
        return;
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int cnt=0;
        int ans=0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]==1){
                    floodFill(grid,i,j,cnt);
                    ans=max(ans,cnt);
                    cnt=0;
                }
            }
        }return ans;
    }
};