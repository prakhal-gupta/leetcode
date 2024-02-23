class Solution {
public:
    static bool cmp(string &lhs, string &rhs){
        string a = lhs + rhs;
        string b = rhs + lhs;
        return a > b;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> vec;
        for(int i=0;i<nums.size();i++){
            vec.push_back(to_string(nums[i]));
        }
        sort(vec.begin(), vec.end(), cmp);
        if(vec[0]=="0")
            return "0";
        string result = "";
        for(int i=0;i<vec.size();i++)
            result +=vec[i];
        return result;
    }
};