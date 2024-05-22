class Solution {
public:
    bool isPalindrome(string &s, int start, int end){
        while(start<end){
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }
    
    void partitionHelper(string& s, int start, vector<string>& partition, vector<vector<string>>& result) {
        if (start == s.length()) {
            result.push_back(partition);
            return;
        }
        for (int end = start; end < s.length(); ++end) {
            if (isPalindrome(s, start, end)) {
                partition.push_back(s.substr(start, end - start + 1));
                partitionHelper(s, end + 1, partition, result);
                partition.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> partition;
        partitionHelper(s, 0, partition, result);
        return result;
    }
};