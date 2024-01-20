class Solution {
public:
    bool halvesAreAlike(string str) {
        int cnt1=0,cnt2=0;
        for(int i=0;i<str.size();i++){
            if(str[i]=='a'|| str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'
               ||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O' ||str[i]=='U'){
                   if(i<str.size()/2)
                    cnt1++;
                    else
                        cnt2++;
            }
        }
        return cnt1==cnt2;
    }
};