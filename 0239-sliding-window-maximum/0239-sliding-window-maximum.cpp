class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> maxInd;

    for (int i = 0; i < nums.size(); i++) {
        while (!maxInd.empty() && maxInd.front() <= i - k)
            maxInd.pop_front();
        while (!maxInd.empty() && nums[maxInd.back()] <= nums[i])
            maxInd.pop_back();
        
        maxInd.push_back(i);
        if (i >= k - 1)
            result.push_back(nums[maxInd.front()]);
    }
    return result;
    }
};