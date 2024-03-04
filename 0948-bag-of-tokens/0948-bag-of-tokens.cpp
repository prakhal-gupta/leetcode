class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int low = 0;
        int high = tokens.size() - 1;
        int score = 0;
        sort(tokens.begin(), tokens.end());

        while (low <= high) {
            if (power >= tokens[low]) {
                score += 1;
                power -= tokens[low];
                low += 1;
            } else if (low < high && score > 0) {
                score -= 1;
                power += tokens[high];
                high -= 1;
            } else {
                return score;
            }
        }
        return score;
    }
};