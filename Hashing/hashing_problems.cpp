class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()<=2)return points.size();
        int ans=0;
        for(int i=0;i<points.size()-ans;++i){
            unordered_map<double,int> mp;
            int local = 0,vertical_points = 1, dublicate = 0;
            for(int j = i+1;j<points.size();++j){
                //first need to handle the two special cases
                //1.slope for vertical points
                //2.account of dublicates value
                if(points[i][0] == points[j][0]){
                    if(points[i][1] == points[j][1]){
                        //means element is dublicate
                        ++dublicate;
                    }else {
                        //vertical point
                        ++vertical_points;
                    }
                }else{
                    double slope = ((points[j][1] - points[i][1])*1.0)/(points[j][0] - points[i][0]);
                    (mp[slope] == 0) ? mp[slope] = 2 : mp[slope]++;
                    local=max(local,mp[slope]);
                }
            }
            int res = max(local + dublicate, dublicate + vertical_points);
            ans = max(ans,res);
        }
        return ans;
    }
};

