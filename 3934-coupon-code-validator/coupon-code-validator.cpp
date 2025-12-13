class Solution {
public:
    static bool validCode(string& s){
        if (s.empty()) return 0;
        for(char c: s){
            if (!isalnum(c) && c!='_') return 0;
        }
        return 1;
    }
    static int validB(string& s){
        int bi=0;
        for (auto& t: {"electronics", "grocery", "pharmacy", "restaurant"}){
            bi++;
            if (t==s) return bi;
        }
        return 0;
    }
    static vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<char, string>> ans;
        const int n=code.size();
        for(int i=0; i<n; i++){
            int bi=0;
            if( isActive[i] && validCode(code[i]) && (bi=validB(businessLine[i])) )
                ans.emplace_back(bi, code[i]);
        }
        sort(ans.begin(), ans.end());
        const int az=ans.size();
        vector<string> ans0(az);
        for(int i=0; i<az; i++)
            ans0[i]=ans[i].second;
        return ans0;
    }
};
const auto init = []() noexcept {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();