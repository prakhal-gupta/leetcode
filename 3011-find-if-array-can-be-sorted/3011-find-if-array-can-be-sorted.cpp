class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> values = nums;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (values[j] <= values[j + 1])
                    continue;
                else {
                    if (__builtin_popcount(nums[j]) == __builtin_popcount(nums[j + 1]))
                        swap(values[j], values[j + 1]);
                    else
                        return false;
                }
            }
        }
        return true;
    }
};