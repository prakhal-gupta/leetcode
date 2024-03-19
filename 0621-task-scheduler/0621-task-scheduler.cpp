class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26);
        for (char task : tasks)
            freq[task - 'A']++;
        sort(freq.begin(), freq.end());
        int maxFreq = freq[25] - 1;
        int idleSlots = maxFreq * n;
        for (int i = 24; i >= 0 && freq[i] > 0; i--)
            idleSlots -= min(maxFreq, freq[i]);
        return idleSlots > 0 ? idleSlots + tasks.size() : tasks.size();
    }
};