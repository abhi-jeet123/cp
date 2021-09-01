class Solution {
public:
    
    int decodeString(string s,int n){
      if(s[0]=='0')return 0;
        int dp[n+1];
       // memset(dp,0,sizeof(dp));
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;++i){
            dp[i]=0;
            if(s[i-1]>'0')dp[i]=dp[i-1];
            if(s[i-2]=='1' or(s[i-2]=='2' and s[i-1]<'7'))dp[i]+=dp[i-2];
        }return dp[n];
    }
    
    
    int numDecodings(string s) {
        int n=s.size();
        //int dp[n+1];
        return decodeString(s,n);
    }
};