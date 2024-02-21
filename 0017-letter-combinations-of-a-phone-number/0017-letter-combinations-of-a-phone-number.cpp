class Solution {
public:
    void backtrack(const string& digits, int i, const unordered_map<char, string>& store, string current, vector<string>& result) {
        if (i == digits.size()) {
            result.push_back(current);
            return;
        }

        for (auto letter : store.at(digits[i])) {
            backtrack(digits, i + 1, store, current+letter , result);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) 
            return {};

        unordered_map<char, string> store = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        vector<string> result;
        backtrack(digits, 0, store, "", result);
        return result;
    }
};