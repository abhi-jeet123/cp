class Solution{
	
	bool getPartition(vector<int>& arr,vector<int>& set1, vector<int>& set2,int sum1,int sum2,int pos){
		if(pos == arr.size()){
			return (sum1 == sum2) ? true : false;
		}
		set1.push_back(arr[pos]);
		bool s1 = getPartition(arr,set1,set2,sum1 + arr[pos], sum2, pos+1);
		
		if(s1)return true;
		
		set1.pop_back(arr[pos]);
		set2.push_back(arr[pos]);
		
		return getPartiton(arr,set1,set2,sum1,sum2+arr[pos],pos+1);
	}
	
	bool isPossible(vector<int>& arr,int n,int sum){
		if(sum == 0) return true;
		if(n==0 and sum !=0 )return false;
		return isPossible(arr,n-1,sum) or isPossible(arr,n-1,sum-arr[n-1]);
	}
	
	bool canPartition(vector<int> arr,int n){
		int sum = 0;
		vector<int> set1,set2;
		for(int i=0;i<n;++i){
			sum+=arr[i];
		}
		bool flag = (sum % 2 == 0) ? isPossible(arr,n,sum/2) : false;
		return (flag) ? getPartition(arr, set1, set2, 0 , 0, 0) : false;
		
	}
}


