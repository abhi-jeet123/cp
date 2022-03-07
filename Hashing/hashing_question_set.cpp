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