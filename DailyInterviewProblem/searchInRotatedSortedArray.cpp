
//In this type of problem we just have to find the pivot element,and do binary search
//in two parts seperately by dividing array in two halfs with respect to pivot element.
//another similar problem search in bitonic array.
class BinarySearchs{
	public:
	int searchs(int arr[],int start, int end, int k){
		bool milGaya = false;
		while(start <= end){
		   int mid = (start + end)/2;
		   if(k > arr[mid]){
		   		start = mid + 1;
		   }else if(k < arr[mid]){
		   		end = mid -1;
		   }else return mid;
		}
		return -1;
	}
};

int Solution::search(const vector<int> &A, int B) {
   // ReverseBinary rb;
	BinarySearchs bs;
    int n = A.size();
    int k = B;
    int arr[n];
    for(int i = 0;i<n;++i)arr[i] = A[i];

    int pivot = 0;
	int milGaya;
	for(int i = 0; i < n - 1 ; ++i){
		if(arr[i] > arr[i+1]){
		    pivot = i;
		    break;}
		
	}if(pivot == 0){
		milGaya = bs.searchs(arr,0,n-1,k);
	}else if(arr[pivot] < k){
		milGaya = -1;
		
	}else{
        int res1 = bs.searchs(arr, pivot + 1, n-1,k);
		//int res1 = rb.reverseSearch(arr,pivot+1,n-1,k);
		int res2 = bs.searchs(arr, 0 , pivot, k);
		
		if(res1==-1 and res2==-1){
			milGaya = -1;
		}else milGaya = max(res1,res2);
	}return milGaya;
}
