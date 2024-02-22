class Solution {
public:
    
    int count(int ind, vector<int> &a){
        if(ind>=a.size()) 
            return 1;
        int ans=0;
        for(int i=ind;i<a.size();i++){
            if(a[i]%(ind+1)==0 || (ind+1)%a[i]==0){
                swap(a[i],a[ind]);
                ans+=count(ind+1,a);
                swap(a[i],a[ind]);
            }
        }
        return ans;
    }
    
    int countArrangement(int n) {
        vector<int> a;
        for(int i=1;i<=n;i++)
            a.push_back(i);
        return count(0,a);
    }
};