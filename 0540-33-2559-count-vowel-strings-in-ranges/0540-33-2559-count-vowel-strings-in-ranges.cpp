class Solution {
private:
    bool isVowel(char &ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
            return true;
        }
        else{
            return false;
        }
    }
    bool isStartEndVowel(string &str){
        int n=str.size();
        if(isVowel(str[0]) && isVowel(str[n-1])){
            return true;
        }
        else{
            return false;
        }
    }

public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        int m=queries.size();
        vector<int> prefix(n);
        prefix[0]=isStartEndVowel(words[0]);
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+isStartEndVowel(words[i]);
        }
        vector<int> ans;
        for(int i=0;i<m;i++){
            int left=queries[i][0];
            int right=queries[i][1];
            int totalStr=0;
            if(left!=0){
                totalStr=prefix[right]-prefix[left-1];
            }
            else{
                totalStr=prefix[right];
            }
            ans.push_back(totalStr);
        }
        return ans;
    }
};