class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordlen=words[0].size();
        int n=words.size();
        int m=s.size();
        vector<int>ans;
        unordered_map<string,int>need;
        for(int i=0;i<n;i++){
            string x=words[i];
            need[x]++;
        }
        int j;
        for(int offset=0;offset<=wordlen-1;offset++){
               j=offset;
               int i=j;
               unordered_map<string,int>mpp;
               int cnt=0;
               while(j+wordlen<=m){
                string window=s.substr(j,wordlen);
                //garbage
                if(!need.count(window)){
                    //reset
                    cnt=0;
                    mpp.clear();
                   
                    i=j+wordlen;
                }else{
                    mpp[window]++;
                    cnt++;

                     // shrink if frequency exceeds
                    while( mpp[window]>need[window]){
                        string start=s.substr(i,wordlen);
                        mpp[start]--;
                        cnt--;
                        if(mpp[start]==0){
                            mpp.erase(start);
                        }
                        i=i+wordlen;
                        window=s.substr(j,wordlen);
                    }
                    //valid window
                    if(cnt==n){
                        ans.push_back(i);
                        //IMPORTANT SLIDE AFTER MATCH
                        //shrink because we want new
                        string start=s.substr(i,wordlen);
                        mpp[start]--;
                        cnt--;
                        if(mpp[start]==0){
                            mpp.erase(start);
                        }
                        i=i+wordlen;
                    }
                }
                j+=wordlen;
                
               }
        }
        return ans;
       
    }
};