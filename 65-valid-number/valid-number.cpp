class Solution {
public:
    bool isNumber(string s) {
        // 1. string should have only engish char i.e. e E
        // 2. e must have some prefix and suffix
        // 3. suffix of e must not contains any decimal i.e. (.)
        // 4. +- or -+ are not allowed (2 otherations or sign togather)
        // 5. only 1 e should be present in string 
        // 6. only 1 . should exist in the string
        // 7. +/- must be at start or followed by e

        bool numSeen = false;
        bool dotSeen = false;
        bool eSeen = false;
        bool numAfterE = true;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                numSeen = true;
                numAfterE = true;
            }
            else if (c == '.') {
                if (dotSeen || eSeen) return false;
                dotSeen = true;
            }
            else if (c == 'e' || c == 'E') {
                if (eSeen || !numSeen) return false;
                eSeen = true;
                numAfterE = false;
            }
            else if (c == '+' || c == '-') {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }
            else {
                return false;
            }
        }

        return numSeen && numAfterE;
    }
};