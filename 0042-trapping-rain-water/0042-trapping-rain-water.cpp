class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3)
            return 0;
        int cap = 0;
        vector<int> leftMax(n), rightMax(n);
        leftMax[0] = height[0];
        rightMax[n - 1] = height[n - 1];
        
        for (int i = 1; i < n; ++i)
            leftMax[i] = max(leftMax[i - 1], height[i]);
        
        for (int i = n - 2; i >= 0; --i)
            rightMax[i] = max(rightMax[i + 1], height[i]);
        
        for (int i = 1; i < n - 1; ++i) {
            int minHeight = min(leftMax[i], rightMax[i]);
            if (minHeight > height[i])
                cap += minHeight - height[i];
        }
        return cap;
    }
};