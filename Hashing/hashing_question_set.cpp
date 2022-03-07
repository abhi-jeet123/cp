// 1-> longest substring with at most two distinct character


int longestSubAtMostTwoChar(string s){
    map<char,int> mp;
    int n = s.size();
    int i=0,j=0;
    int ans = 0;
    while(j<n){
       if(mp.find(s[j]) != mp.end() or (mp.find(s[j]) == mp.end() and (mp.size() < 2))){
           mp[s[j]]++;
           ans = max( ans , j - i + 1);
           ++j;
       }else{
           while(mp.size()>=2){
               mp[s[i]]--;
               if(mp[s[i]] == 0)mp.erase(s[i]);
               ++i;
           }
       }
       
    }return ans;
}

//2-> Longest Subarray of 1's After Deleting One Element

//Given a binary array nums, you should delete one element from it.

//Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.


class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt = 0;
        int i = 0 , j = 0 ;
        int ans = 0;
        for( ; j<nums.size() ; ++j){
            cnt+=nums[j]==0;
            while(cnt>1){
                if(nums[i++]==0)cnt-=1;
            }
            ans = max(ans,j-i);//here returning j - i beacuse at end we have to delete one character also
        }return ans;
    }
};

//3-> Longest substring with atmost k different characters

int longestSubAtMostKChar(string s, int k){
    map<char,int> mp;
    int n = s.size();
    int i=0,j=0;
    int ans = 0;
    while(j<n){
       if(mp.find(s[j]) != mp.end() or (mp.find(s[j]) == mp.end() and (mp.size() < k))){
           mp[s[j]]++;
           ans = max( ans , j - i + 1);
           ++j;
       }else{
           while(mp.size()>=k){
               mp[s[i]]--;
               if(mp[s[i]] == 0)mp.erase(s[i]);
               ++i;
           }
       }
       
    }return ans;
}

//4-> Given a binary array, find the maximum number of consecutive 1s in this array if you can flip at most one 0.

int getLen(int arr[],int n){
     int i = 0 , j = 0;
     int ans = 0;
     int cnt = 0;
     for( ;j < n ; ++j ){
         cnt+=arr[j]==0;
         while(cnt>1)cnt-=arr[i++]==0;
         ans = max ( ans , j - i + 1);
     }
     return ans;
 }

 //5-> Subarray Product Less Than K

//Given an array of integers nums and an integer k, return the number of contiguous
// subarrays where the product of all the elements in the subarray is strictly less 
 //than k.

 //so in this type of problem where we have to count all the subarray with the given condition
 //we can use sliding window in such a way that ,we will evauluate every time after incrementing
 // j i.e number of subarray it will form from i to j.

 class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0 ,j = 0;
        int n=nums.size();
        int ans = 0;
        int sum = 1;
        for( ; j < n ; ++j){
            sum *= nums[j];
            while(i<=j and sum >= k){
                sum = sum/nums[i++];
            }
            ans += j - i + 1;
        }
        return ans;
    }
};
//Frequency of the Most Frequent Element

//occurs in an array.

//You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.

//Return the maximum possible frequency of an element after performing at most k operations.
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long ans = 0;
        long i = 0, j = 0;
        long sum = 0;
        for( ; j< nums.size();++j){
            sum += nums[j];
            while( (j-i+1) * nums[j] - sum > k)sum -=nums[i++];
            ans = max(ans,j-i+1);
        }
        return ans;
        
        
    }
};
//in this hashing our window compression will be done by
//while((j-i+1)*nums[j]-sum>k)sum-=nums[i++];
//i.e assuming the jth index as the element to make other elements equal,
//and if we go summing them,we can easily find how many operationi.e additon of one required
//is greater or less than k,and accordingly we will move gthe window.

//***************************************************

//Maximum Erasure Value

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = 0;
        int sum = 0;
        int i = 0, j = 0;
        for( ; j < nums.size(); ++j){
            sum += nums[j];
            while(mp.count(nums[j])){
                mp.erase(nums[i]);
                sum -= nums[i++];
            }
            mp[nums[j]] += 1;
            ans = max(ans,sum);
        }
        return ans;
    }
};


//Longest Substring Without Repeating Characters

class Solution {
public:
    int lengthOfLongestSubstring(string nums) {
    
    unordered_map<int,int> mp;
    int ans = 0;
    int i = 0,j = 0;
    for( ;j < nums.size() ; ++j){
        while(mp.count(nums[j])){
            mp.erase(nums[i++]);
        }
        mp[nums[j]]+=1;
        ans = max(ans,j-i+1);
    }return ans;
    }
};


