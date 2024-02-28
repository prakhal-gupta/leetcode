class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        stack<int> st;
        // for(int i=n-1;i>=0;i--){
        //     while(!st.empty() && st.top() <=nums[i])
        //         st.pop();
        //     if(st.empty())
        //         ans[i]=-1;
        //     else
        //         ans[i] = st.top();
        //     st.push(nums[i]);
        // }
        for (int i = 0; i < 2 * n; i++) {
            int index = i % n;
            while (!st.empty() && nums[st.top()] < nums[index]) {
                ans[st.top()] = nums[index];
                st.pop();
            }
            if (i < n)
                st.push(i);
        }
        return ans;
    }
};