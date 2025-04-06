class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int>v(n,1),res;
        int maxa = 1,num = -1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j] == 0 && v[i] <v[j]+1){
                    v[i] = max(v[i],1+v[j]);
                    maxa = max(maxa,v[i]);
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            if(v[i] == maxa && (num == -1 || !(num % nums[i]))){
                maxa--;
                res.push_back(nums[i]);
                num = nums[i];
            }
        }
        return res;
    }
};