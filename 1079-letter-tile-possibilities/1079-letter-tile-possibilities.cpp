class Solution {
public:
    void rightShift(int i, int j, string &s){
    char x =s[j];
    for(int k=j;k>i;k--)
        s[k]=s[k-1];
    s[i] =x;
    }

    void leftShift(int i, int j, string &s){
        char x =s[i];
        for(int k=i;k<j;k++)
            s[k]=s[k+1];
        s[j] =x;
    }
    
    void backtrack(int i, string &s, int &count, int n){
    if(i==n){
        count++;
        cout << s <<endl;
        return;
    }
    vector<bool> flag(256, false);
    for(int j=i;j<s.size();j++){
        if(!flag[s[j]]){
            flag[s[j]] = true;
            rightShift(i,j, s);
            backtrack(i+1,s, count, n);
            leftShift(i,j,s);
        }   
    }
        return;
    }
    
    int numTilePossibilities(string tiles) {
        int count = 0;
        for(int i=1;i<=tiles.size();i++){
            backtrack(0,tiles, count, i);
        }
    return count;
    }
};