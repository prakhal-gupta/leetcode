class Solution {
public:
    int minSwaps(string s) {
        stack<char> stack;
        int unbalanced = 0;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == '[')
                stack.push(ch);
            else {
                if (!stack.empty()) stack.pop();
                else
                    unbalanced++;
            }
        }
        return (unbalanced + 1) / 2;
    }
};