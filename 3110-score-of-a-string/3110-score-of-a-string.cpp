class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;
        // Iterate over all indices from 0 to the second-to-last index
        // Calculate and accumulate the absolute difference of ASCII values
        // between adjacent characters
        for (int i = 0; i < s.size() - 1; ++i) {
            score += abs(s[i] - s[i + 1]);
        }
        return score;
    }
};