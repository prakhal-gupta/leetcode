class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m * n != original.size())
            return vector<vector<int>>(0, vector<int>(0));
        vector<vector<int>> resultArray(m, vector<int>(n));
        for (int i = 0; i < original.size(); i++)
            resultArray[i / n][i % n] = original[i];
        return resultArray;
    }
};