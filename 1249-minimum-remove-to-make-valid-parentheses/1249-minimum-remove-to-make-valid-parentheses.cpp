class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int openParenthesesCount = 0;
        vector<char> arr(s.begin(), s.end());
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == '(')
                openParenthesesCount++;
            else if (arr[i] == ')') {
                if (openParenthesesCount == 0)
                    arr[i] = '*';
                else
                    openParenthesesCount--;
            }
        }
        for (int i = arr.size() - 1; i >= 0; i--) {
            if (openParenthesesCount > 0 && arr[i] == '(') {
                arr[i] = '*';
                openParenthesesCount--;
            }
        }
        string result = "";
        for (char c : arr) {
            if (c != '*')
                result += c;
        }
        return result;
    }
};