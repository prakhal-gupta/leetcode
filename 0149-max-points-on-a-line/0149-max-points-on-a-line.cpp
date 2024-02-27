class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans =1;
        for(int i=0;i<points.size();i++){
            unordered_map <double,int> mp;
            for(int j=0;j<points.size();j++){
                double temp;
                if(i!=j){
                    temp = double(points[i][0] - points[j][0])/(points[i][1] - points[j][1]);
                    mp[atan(temp)]++;
                }
                ans = max(ans,mp[atan(temp)]+1);
            }
        }
        return ans;
    }
};