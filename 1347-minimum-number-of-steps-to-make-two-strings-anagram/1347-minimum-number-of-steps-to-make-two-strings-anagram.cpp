class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        int ans=0;
        for(int i=0;i<t.size();i++){
            if(mp.find(t[i])==mp.end())
                ans++;
            else{
                if(mp[t[i]]>0){
                    mp[t[i]]--;
                }
                else{
                    ans++;
                }
            }
        }
        return ans;
    }
};