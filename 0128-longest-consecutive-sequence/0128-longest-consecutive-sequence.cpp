class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
            return 0;
        int cnt=1, longest=1;
        unordered_set<int> us;
        for(int i =0;i<n;i++)
            us.insert(nums[i]);
        for(auto it : us){
            if(us.find(it -1) == us.end()){
                cnt = 1;
                int x = it;
                while(us.find(x+1) != us.end()){
                    cnt++;
                    x=x+1;
                }
            }
            longest = max(longest, cnt);
        }
        return longest;
    }
};