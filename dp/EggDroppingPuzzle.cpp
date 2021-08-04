class Solution {
public:
    
    int solve(int n,int f, vector<vector<int>> &memo){
        if(f==0 or f==1)return f;
        if(n==1)return f;
        
        if(memo[n][f]!=-1)return memo[n][f];
        
        int ans=INT_MAX-2;
        int l=1,h=f;
        while(l<=h){
            int mid=(l+h)/2;
            int left=solve(n-1,mid-1,memo);
            int right=solve(n,f-mid,memo);
            int temp=1+max(left,right);
            //max to get the worst case ans
            if(left<right)l=mid+1;
            //if right is greater ,thrn to get more worst we woud go on right side
            else h=mid-1;
            //else if left is greater ,so to get worst we will go left side
           ans=min(temp,ans);//min to get the min attempt of all worst cases
            
        }

        
        return memo[n][f]=ans;
    }
    
    int superEggDrop(int n, int f) {
        vector<vector<int>> memo(n+1,vector<int>(f+1,-1));
        
        return solve(n,f,memo);
        
    }
};