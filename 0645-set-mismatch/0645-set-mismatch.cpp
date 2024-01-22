class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int a,b,n=nums.size();
        vector<int>freq(n+1,0);
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        for(int i=1;i<=n;i++){
            if(freq[i]==0)
                a=i;
            if(freq[i]>1)
                b=i;
        }
        return {b,a};
    }
};