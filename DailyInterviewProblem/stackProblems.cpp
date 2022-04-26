#include<bits/stdc++.h>
using namespace std;

void nextGreater(int *arr,int n){
	stack<int> s;
	s.push(arr[0]);
	for(int i=1;i<n;++i){
		if(s.empty()){
			s.push(arr[i]);
			continue;
		}else{
			while(s.empty()==false and s.top()<=arr[i]){
				int greater = (s.empty()) ? -1 : s.top();
				s.pop();
				cout<<greater<<"-->"<<arr[i]<<endl;
			}s.push(arr[i]);
		}
	}while(!s.empty()){
		cout<<s.top()<<"-->"<<"-1"<<endl;
		s.pop();
	}
}
void previousGreater(int *arr,int n){
	stack<int> s;
	s.push(arr[0]);
	cout<<arr[0]<<"-->"<<"-1"<<endl;
	for(int i=1;i<n;++i){
		while(!s.empty() and s.top()<arr[i]){
			s.pop();
		}
		int greater = (s.empty()) ? -1 : s.top();
		cout<<arr[i]<<"-->"<<greater<<endl;
	}s.push(arr[i]);
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;++i)cin>>arr[i];
	nextGreater(arr,n);
	return 0;
}