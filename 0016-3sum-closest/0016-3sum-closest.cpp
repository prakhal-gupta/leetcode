class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = INT_MAX;
        int sum =0;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            int j = i+1, k=nums.size()-1;
            int tar = target - nums[i];
            while(j<k){
                if(abs(target - (nums[i] + nums[j] + nums[k])) < ans){
                    ans = abs(target - (nums[i] + nums[j] + nums[k]));
                    sum = nums[i] + nums[j] + nums[k];
                }
                if(nums[j]+nums[k]>=tar)
                    k--;
                else
                    j++;
            }
        }
        return sum;
    }
};