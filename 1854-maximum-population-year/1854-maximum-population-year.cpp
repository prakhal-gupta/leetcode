class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> prefixSum(101, 0);
        for (int i = 0; i < logs.size(); i++) {
            prefixSum[logs[i][0] - 1950]++;
            prefixSum[logs[i][1] - 1950]--;
        }
        for (int i = 1; i < prefixSum.size(); i++)
            prefixSum[i] = prefixSum[i - 1] + prefixSum[i];
        
        int maxPopulation = 0;
        int maxYear = 0;
        for (int i = 0; i < prefixSum.size(); i++) {
            if (prefixSum[i] > maxPopulation) {
                maxPopulation = prefixSum[i];
                maxYear = i;
            }
        }
        
        return maxYear + 1950;
    }
};
