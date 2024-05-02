class Solution {
public:
    int findMaxK(std::vector<int>& nums) {
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        int ans = -1;
        for (int i : numSet) {
            if (numSet.find(-i) != numSet.end())
                ans = std::max(ans, std::abs(i));
        }
        return ans;
    }
};