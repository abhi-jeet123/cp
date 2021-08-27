class Solution {
public:
    
    void floodFill(vector<vector<char>>& grid,int i,int j){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size())return;
        if(grid[i][j]=='2' or grid[i][j]=='0')return;
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
                if(grid[i][j]=='1'){
                    floodFill(grid,i,j);
                    ++cnt;
                }
            }
        }return cnt;
    }
};