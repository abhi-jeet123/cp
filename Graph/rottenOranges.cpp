class Solution {
public:
    
    bool isPossible(int i,int j,vector<vector<int>>& grid){
    if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size())return false;

    if(grid[i][j]==1){
        grid[i][j]=2;
        return true;
    }

    return false;

}
    
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty())return -1;
             queue<pair<int,int>> q;
     int cnt=0;
     for(int i=0;i<grid.size();++i){
         for(int j=0;j<grid[0].size();++j){
             if(grid[i][j]==2)q.push(make_pair(i,j));
             if(grid[i][j]!=0)cnt++;
         }
     }
     //q.push(make_pair(-1,-1));//seperater for every minute rotten orange
     int minute=0,rot=0;
     while(!q.empty()){
         int n=q.size();

         for(int i=0;i<n;++i){
             rot++;
             pair p=q.front();
             q.pop();
             if(isPossible(p.first+1,p.second,grid)){
                 q.push(make_pair(p.first+1,p.second));
             }
             if(isPossible(p.first-1,p.second,grid)){
                 q.push(make_pair(p.first-1,p.second));
             }
             if(isPossible(p.first,p.second-1,grid)){
                 q.push(make_pair(p.first,p.second-1));
             }
             if(isPossible(p.first,p.second+1,grid)){
                 q.push(make_pair(p.first,p.second+1));
             }
         }if(!q.empty())minute++;
     }
     if(rot==cnt)return minute;
     else return -1;
    }
};