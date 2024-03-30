class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return slidingWindowAtMost(nums, k) - slidingWindowAtMost(nums, k - 1);
    }

private:
    int slidingWindowAtMost(vector<int>& nums, int distinctK) {
        map<int, int> freqMap;
        int left = 0, totalCount = 0;
        for (int right = 0; right < nums.size(); right++) {
            freqMap[nums[right]]++;
            while (freqMap.size() > distinctK) {
                freqMap[nums[left]]--;
                if (freqMap[nums[left]] == 0) 
                    freqMap.erase(nums[left]);
                left++;
            }
            totalCount += (right - left + 1);
        }
        return totalCount;
    }
};