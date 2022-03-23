



//Given an array A, maximize value of expression (A[s] - A[r] + A[q] - A[p]), 
//where p, q, r, and s are indices of the array and s > r > q > p.







int getMaxValueOfExpression(int arr[],int n){
	if(n<4)return -1;
	vector<int> first(n+1,INT_MIN);
	vector<int> second(n,INT_MIN);
	vector<int> third(n-1,INT_MIN);
	vector<int> forth(n-2,INT_MIN);
	
	for(int i = n-1; i >= 0 ; --i){
		first[i] = max(first[i+1],arr[i]);
	}
	for(int i = n-2; i >= 0; --i){
		second[i] = max(second[i+1] , first[i+1] - arr[i]);
	}
	for(int i = n-3; i >= 0 ; --i){
		third[i] = max(third[i+1],second[i+1]+arr[i]);
	}
	for(int i = n-4; i >= 0; --i){
		forth[i] = max(forth[i+1],third[i+1]-arr[i]);
	}
	return forth[0];
}