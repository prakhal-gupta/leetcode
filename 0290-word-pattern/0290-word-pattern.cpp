class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string temp;
        vector<string> ss;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ')
                temp.push_back(s[i]);
            else if (s[i] == ' ') {
                if (!temp.empty()) {
                    ss.push_back(temp);
                    temp.clear();
                }
            }
        }
        if (!temp.empty())
            ss.push_back(temp);   
        map<char, string> mp1;
        map<string, char> mp2;
        if (pattern.length() != ss.size()) return false;
        for (int i = 0; i < pattern.length(); i++) {
            char c = pattern[i];
            string w = ss[i]; 
            if (mp1.count(c)) {
                if (mp1[c] != w) return false;
            } else
                mp1[c] = w;
            if (mp2.count(w)) {
                if (mp2[w] != c) return false;
            } else
                mp2[w] = c;
        }
        return true;
    }
};