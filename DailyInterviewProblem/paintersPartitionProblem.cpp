
bool isPossible(vector<int> arr, int num, int minDays , int b){
	long long int worker = 1;
	long long int curr_days = 0;
    long long int sum = 0;
    //for(int i=0;i<arr.size();++i)sum += arr[i];

	for(int i = 0;i < arr.size() ; ++i){
		if(curr_days + (arr[i]) > minDays){
            if(arr[i] > minDays)return false;
			++worker;
			curr_days = arr[i]%10000003;
			if(worker > num){
				return false;
			}
		}else curr_days += ((arr[i])%10000003);
	}
	return true;
}

int Solution::paint(int num, int b, vector<int> &arr) {
    
	long long int s = 0 , e = 0;
	for(int i = 0;i < arr.size() ; ++i) e += ((arr[i])%10000003);
    e = (e * b)%10000003;
    long long int ans = INT_MAX;
    //e *= b;
	long long int mid ; 
	while( s <= e){
		mid = s + (e - s)/2;
		if(isPossible( arr, num , mid , b)){
			ans = min(ans , mid%10000003);
			e = mid -1;
		}else s = mid + 1;
	}
	return (int)((ans*(long long int)b)%10000003);
}
