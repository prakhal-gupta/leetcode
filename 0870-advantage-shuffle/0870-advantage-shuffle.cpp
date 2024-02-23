class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(),-1);
        vector<pair<int,int>> vec2;
        for(int i=0;i<nums1.size();i++)
            vec2.push_back({nums2[i],i});
        
        sort(nums1.begin(), nums1.end());
        sort(vec2.begin(), vec2.end());
        
        int j=nums1.size()-1;
        int i=j;
        while(i>=0 && j>=0){
            if(nums1[i]>vec2[j].first){
                ans[vec2[j].second]=nums1[i];
                i--;
                j--;
            }
            else
                j--;
        }

        for(int k=0;k<ans.size();k++){
            if(ans[k]==-1){
                ans[k]=nums1[i];
                i--;
            }
        }
        return ans;
    }
};