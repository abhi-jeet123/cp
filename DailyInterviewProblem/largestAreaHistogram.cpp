int largestAreaHistogram(vector<int> arr,int n){
	stack<int> s;
	int i = 0;
	s.push(arr[i]);
	int max_area = 0;
	int top_area = 0;
	while(i<n){
		if(s.empty() or arr[s.top()] <= arr[i]){
			s.push(arr[i++]);
		}else{
			int x = s.top();
			s.pop();
			area = arr[x] * ((s.empty()) ? i : i - s.top() - 1);
			max_area = max(max_area,area_top);
		}
	}while(!s.empty()){
		int x = s.top();
		s.pop();
		area_top = arr[x] * ((s.empty()) ? i : i - s.top() - 1);
		max_area = max(max_area,area_top);
	}return max_area;
}