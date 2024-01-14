class Solution {
public:
    bool closeStrings(string word1, string word2) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if(word1.size()!=word2.size())
            return false;
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for(int i=0;i<word1.size();i++){
            freq1[word1[i]-'a']++;
            freq2[word2[i]-'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if ((freq1[i] == 0 && freq2[i] != 0) || (freq1[i] != 0 && freq2[i] == 0)) {
                return false;
            }
        }

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        return freq1==freq2;
    }
};