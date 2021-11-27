class Solution {
public:
    
    bool dfs(vector<vector<char>>& board,int i,int j,string &word){
        if(word.size()==0){
            return true;
            //means word is present
        }
        if(i<0 or i>=board.size() or j<0 or j>=board[0].size() or board[i][j]!=word[0]){
            return false;
        }
        char ch=board[i][j];
        board[i][j]='*';
        string s=word.substr(1);
        bool ans=dfs(board,i-1,j,s) or dfs(board,i+1,j,s) or dfs(board,i,j-1,s) or dfs(board,i,j+1,s);
        
        board[i][j]=ch;//backtrack
        return ans;
        
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(dfs(board,i,j,word)){
                    return true;
                }
            }
        }
        return false;
    }
};