 #include<bits/stdc++.h>
 using namespace std;


bool comp(pair<int,int> p1,pair<int,int> p2){
    return p1.second < p2.second;
}

 int minRooms(vector<pair<int,int>> interval,int n){
     sort(interval.begin(),interval.end(),comp);
     
     for(auto &c:interval){
         int temp=c.first;
         c.first=c.second;
         c.second=temp;
     }
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
     pq.push(interval[0]);
     for(int i=1;i<n;++i){
         pair<int,int> p1=pq.top();
         pair<int,int> p2=interval[i];
         pq.pop();
         if(p1.first<=p2.second){
             p1.first=p2.first;
         }else {
             pq.push(p2);
         }
         pq.push(p1);
     }
     int ans=pq.size();
     while(!pq.empty()){
         pair<int,int> p1=pq.top();
         pq.pop();
         //cout<<p1.first<<"  "<<p1.second<<endl;
     }
     return ans;
 }

 int main(){
     int n;
     cin>>n;
     vector<pair<int,int>> interval;
     for(int i=0;i<n;++i){
         int a,b;
         cin>>a>>b;
         interval.push_back(make_pair(a,b));
         
     }cout<<minRooms(interval,n);
 }