class Solution {
public:
    bool solve(string s,string p){
        sort(s.begin(),s.end());
        return s==p;
    }
    bool checkInclusion(string s1, string s2) {
        map<string,int> mapp;
        sort(s1.begin(),s1.end());
        for(int p=0;p+s1.size()<=s2.size();p++)
            mapp[s2.substr(p,s1.size())]++;
        for(auto it=mapp.begin();it!=mapp.end();it++){
            if(solve(it->first,s1))
                return 1;
        }
        return 0;
    }
};