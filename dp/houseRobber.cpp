class Solution {
public:
    
    int solve(vector<int> arr,int i,int *dp){
    if(i<0)return 0;
    if(dp[i]!=-1)return dp[i];
    return dp[i]=max(arr[i]+solve(arr,i-2,dp),solve(arr,i-1,dp));
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        int dp[n+1];
        memset(dp,-1,sizeof(dp));
        return solve(nums,n-1,dp);
    }
};