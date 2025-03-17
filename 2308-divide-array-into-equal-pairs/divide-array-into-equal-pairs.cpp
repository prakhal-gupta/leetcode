class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int pos = 0; pos < nums.size(); pos += 2) {
            if (nums[pos] != nums[pos + 1])
                return false;
        }
        return true;
    }
};