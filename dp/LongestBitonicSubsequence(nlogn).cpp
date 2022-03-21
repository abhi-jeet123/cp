class Solution {
public:
    
vector<int> lengthOfLIS(vector<int>& nums,int n) {
	vector<int> dp(n);
	dp[0]=1;
       // int n=nums.size();
        vector<int> res;
        res.push_back(nums[0]);
        for(int i=1;i<n;++i){
            if(nums[i]>res.back()){
                res.push_back(nums[i]);
            }else{
                int x=lower_bound(res.begin(),res.end(),nums[i])-res.begin();
                res[x]=nums[i];
            }
            dp[i]=res.size();
        }
        // for(int i = 0;i < n; ++i){
        // 	cout<<dp[i]<<" ";
        // }cout<<endl;
        return dp;
    }
  vector<int> lengthOfLdS(vector<int>& nums,int n) {
	vector<int> dp(n);
	dp[0]=1;
       // int n=nums.size();
        vector<int> res;
        res.push_back(nums[0]);
        for(int i=1;i<n;++i){
            if(nums[i]>res.back()){
                res.push_back(nums[i]);
            }else{
                int x=lower_bound(res.begin(),res.end(),nums[i])-res.begin();
                res[x]=nums[i];
            }
            dp[i]=res.size();
        }
        // for(int i = 0;i < n; ++i){
        // 	cout<<dp[i]<<" ";
        // }cout<<endl;
        return dp;
    }
    
    int solve(vector<int> nums,int n){
        vector<int> dp1 = lengthOfLIS(nums,n);
        reverse(nums.begin(),nums.end());
        vector<int> dp2 = lengthOfLdS(nums,n);
        reverse(dp2.begin(),dp2.end());
        //cout<<endl;
        int ans = INT_MIN;
        for(int i = 0;i<n;++i){
            if(dp1[i]>1 and dp2[i]>1)
            ans = max(ans,dp1[i]+dp2[i]-1);
        }return ans;
    }
    
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        int temp=solve(nums,n);
        return (n-temp);
    }
};