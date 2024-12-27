class Solution {
public:
    int addDigits(int num) {
        string s=to_string(num);
        int k=10;
        while(k>9)
        {
            k=0;
            for(int i=0;i<s.size();i++)
            {
                k+=s[i]-48;
            }
            s=to_string(k);
        }
        return k;
    }
};