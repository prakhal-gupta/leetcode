class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> frequencies;
        for (int num : nums) {
            frequencies[num]++;
        }
        int maxFrequency = 0;
        for (auto [num, frequency] : frequencies) {
            maxFrequency = max(maxFrequency, frequency);
        }
        int frequencyOfMaxFrequency = 0;
        for (auto [num, frequency] : frequencies) {
            if (frequency == maxFrequency) {
                frequencyOfMaxFrequency++;
            }
        }
        return frequencyOfMaxFrequency * maxFrequency;
    }
};