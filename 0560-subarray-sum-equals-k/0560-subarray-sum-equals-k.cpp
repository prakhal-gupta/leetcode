class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0, sum=0;
        unordered_map<int, int> seenSum;
        for (int i = 0; i <nums.size(); i++) {
            sum += nums[i];
            if (sum == k) {
                ans++;
            }
            if (seenSum.find(sum - k) != seenSum.end()) {
                ans+=seenSum[sum - k];
            }
            seenSum[sum]++;
        }
        return ans;
    }
};