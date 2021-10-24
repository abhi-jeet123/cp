class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n=nums.size();
        if(n<3)return 0;
        vector<int> dp(nums.size());
        int sum=0;
        dp[0]=0;
        dp[1]=0;
        for(int i=2;i<n;++i){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                dp[i]=1+dp[i-1];
            }else dp[i]=0;
            
            sum+=dp[i];
        }
        return sum;
    }
};