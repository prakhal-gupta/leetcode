class Solution {
public:
    void backtrack(int i, vector<int>& arr, int target,
                   vector<vector<int>>& res, vector<int>& curr) {
        if (i == arr.size()) {
            if (target == 0) res.push_back(curr);
            return;
        }

        if (arr[i] <= target) {
            curr.push_back(arr[i]);
            backtrack(i, arr, target - arr[i], res, curr);
            curr.pop_back();
        }

        backtrack(i + 1, arr, target, res, curr);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(0, candidates, target, res, curr);
        return res;
    }
};