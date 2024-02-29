class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int maxArea = 0;
        int i = 0;
        while (i < heights.size()) {
            if (s.empty() || heights[i] >= heights[s.top()]) {
                s.push(i);
                i++;
            } else {
                int tp = s.top();
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                maxArea = max(maxArea, heights[tp] * width);
            }
        }
        while (!s.empty()) {
            int tp = s.top();
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, heights[tp] * width);
        }
        return maxArea;
    }
};