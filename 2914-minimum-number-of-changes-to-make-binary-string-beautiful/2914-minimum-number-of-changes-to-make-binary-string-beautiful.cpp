class Solution {
public:
    int minChanges(string s) {
        char currentChar = s[0];
        int consecutiveCount = 0;
        int minChangesRequired = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == currentChar) {
                consecutiveCount++;
                continue;
            }
            if (consecutiveCount % 2 == 0)
                consecutiveCount = 1;
            else {
                consecutiveCount = 0;
                minChangesRequired++;
            }
            currentChar = s[i];
        }
        return minChangesRequired;
    }
};