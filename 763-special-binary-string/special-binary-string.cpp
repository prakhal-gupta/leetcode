#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string makeLargestSpecial(string s) 
    {
        vector<string> subs;
        int count = 0, start = 0;
        
        // Split the string into top-level special substrings
        for (int i = 0; i < s.size(); i++) 
        {
            count += (s[i] == '1' ? 1 : -1);
            if (count == 0) 
            {
                // s[start..i] is a special substring
                // Recursively process the inside (strip outer 1 and 0)
                subs.push_back
                (
                    "1" + makeLargestSpecial(s.substr(start + 1, i - start - 1)) + "0"
                );
                start = i + 1;
            }
        }
        
        // Sort in descending lexicographic order
        sort(subs.begin(), subs.end(), greater<string>());
        
        // Join and return
        string result;
        for (auto &str : subs) result += str;
        return result;
    }
};