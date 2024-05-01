class Solution {
public:
    string reversePrefix(string word, char ch) {
        int chIndex = word.find(ch);
        reverse(word.begin(), word.begin() + chIndex + 1 );
        return word;
    }
};