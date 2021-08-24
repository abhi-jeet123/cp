class Solution {
public:
    
    void flood_fill(vector<vector<char>>& matrix,int i,int j,char prev,char change){
        if(i<0 or j<0 or i>=matrix.size() or j>=matrix[0].size())return;
        if(matrix[i][j]!=prev)return;
        matrix[i][j]=change;
        flood_fill(matrix,i+1,j,prev,change);
        flood_fill(matrix,i-1,j,prev,change);
        flood_fill(matrix,i,j+1,prev,change);
        flood_fill(matrix,i,j-1,prev,change);
        return;
    }
    
    void solve(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(matrix[i][j]=='O'){
                    matrix[i][j]='_';
                }
            }
        }
        for(int j=0;j<m;++j){
            if(matrix[0][j]=='_'){
                flood_fill(matrix,0,j,'_','O');
            }
        }
        for(int j=0;j<m;++j){
            if(matrix[n-1][j]=='_'){
                flood_fill(matrix,n-1,j,'_','O');
            }
        }
        for(int j=0;j<n;++j){
            if(matrix[j][0]=='_'){
                flood_fill(matrix,j,0,'_','O');
            }
        }
        for(int j=0;j<n;++j){
            if(matrix[j][m-1]=='_'){
                flood_fill(matrix,j,m-1,'_','O');
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(matrix[i][j]=='_')matrix[i][j]='X';
            }
        }
        return ;
    }
};