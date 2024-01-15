class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        unordered_map<int,int> lose;
        set<int> s;
        for(auto x:matches){
            lose[x[1]]++;
            s.insert(x[0]);
            s.insert(x[1]);
        }
        vector<int>ans1,ans2;
        for(auto x:s){
            if(lose.find(x)==lose.end())
                ans1.push_back(x);
            else if(lose[x]==1)
                ans2.push_back(x);
        }
        return {ans1,ans2};
    }
};