class Solution {
public:
    int mod = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = arr.size();
        vector<long> dp(n);
        stack<int> st;
        long sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] < arr[st.top()])
                st.pop();
            if (st.empty())
                dp[i] = ((arr[i] % mod) * ((n - i) % mod)) % mod;
            else
                dp[i] =
                    ((arr[i] * (st.top() - i)) % mod + (dp[st.top()]) % mod) %
                    mod;
            st.push(i);
            sum = (sum % mod + dp[i] % mod) % mod;
        }
        return sum;
    }
};