class Solution {
public: 
    bool checkValidString(string s) {
        vector<vector<int>> memo(s.size(), vector<int>(s.size(), -1));
        return isValidString(0, 0, s, memo);
    }
private: 
    bool isValidString(int index, int openCount,
        const string & str, vector < vector < int >> & memo) {
        if (index == str.size())
            return (openCount == 0);
        if (memo[index][openCount] != -1)
            return memo[index][openCount];

        bool isValid = false;
        if (str[index] == '*') {
            isValid |= isValidString(index + 1, openCount + 1, str, memo);
            if (openCount) {
                isValid |= isValidString(index + 1, openCount - 1, str, memo);
            }
            isValid |= isValidString(index + 1, openCount, str, memo);
        } else {
            if (str[index] == '(')
                isValid = isValidString(index + 1, openCount + 1, str, memo);
            else if (openCount)
                isValid = isValidString(index + 1, openCount - 1, str, memo);
        }
        return memo[index][openCount] = isValid;
    }
};