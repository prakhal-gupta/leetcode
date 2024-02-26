class Solution {
public:
    bool isValid(unordered_map<char,int> &fs, unordered_map<char,int> &ft){
        for(auto it: ft){
            if(fs[it.first]<it.second)
                return false;
        }
        return true;
    }
    
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || t.size()> s.size()) {
            return "";
        }
        unordered_map<char, int> fs;
        unordered_map<char, int> ft;
        for (char c : t) {
            int count = ft[c];
            ft[c] = count + 1;
        }
        
        int l=0,r=0,ans = -1, ind=0;
        while(r<s.size()){
            if(ft.find(s[r]) != ft.end()) {
                fs[s[r]]+=1;
            }
            r++;
            if(isValid(fs,ft)){
                while(true){
                    if(ft.find(s[l]) != ft.end()) {
                        fs[s[l]]--;
                        if(isValid(fs,ft))
                            l++;
                        else{
                            fs[s[l]]++;
                            break;
                        }
                    } else {
                        l++;
                    }
                }
                if((r-l)<ans || ans==-1){
                    ans = r-l;
                    ind =l;
                }
            }
        }
        if(ans==-1)
            return "";
        cout <<"ind"<<ind << "ans" <<ans << endl;
        return s.substr(ind, ans);

//         int required = dictT.size();
//         int l = 0, r = 0;
//         int formed = 0;

//         unordered_map<char, int> windowCounts;
//         int ans[3] = { -1, 0, 0 };

//         while (r < s.length()) {
//             char c = s[r];
//             int count = windowCounts[c];
//             windowCounts[c] = count + 1;

//             if (dictT.find(c) != dictT.end() && windowCounts[c] == dictT[c]) {
//                 formed++;
//             }

//             while (l <= r && formed == required) {
//                 c = s[l];

//                 if (ans[0] == -1 || r - l + 1 < ans[0]) {
//                     ans[0] = r - l + 1;
//                     ans[1] = l;
//                     ans[2] = r;
//                 }

//                 windowCounts[c]--;
//                 if (dictT.find(c) != dictT.end() && windowCounts[c] < dictT[c]) {
//                     formed--;
//                 }

//                 l++;
//             }

//             r++;
//         }

//         return ans[0] == -1 ? "" : s.substr(ans[1], ans[0]);
    }
};