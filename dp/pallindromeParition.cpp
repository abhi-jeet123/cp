
bool isPallindrome(string s,int i,int j){
	if(i==j)return true;
	while(i<=j){
		if(s[i++] != s[j--])
			return false;
	}
	return true;
}

int partitionString(string s,int start,int end){
	if(start == end or isPallindrome(s,start,end)){
		return 0;
	}
	int cnt = INT_MAX;
	for(int i = start + 1 ; i<end ; ++i){
		int res = 1 + partitionString(s,start,i) + partitionString(s,i+1,end);
		cnt = min(cnt , res);
	}return cnt;
	
}

