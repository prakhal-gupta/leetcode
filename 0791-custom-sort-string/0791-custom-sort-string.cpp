class Solution {
public:
    string customSortString(string order, string s) {
        string str = "";
        map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }

        for (char c : order) {
            if (mp.find(c) != mp.end()) {
                str.append(mp[c], c);
                mp.erase(c);
            }
        }

        for (auto i = mp.begin(); i != mp.end(); i++) {
            str.append(i->second, i->first);
        }

        return str;
    }
};