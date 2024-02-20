class Solution {
public:
    bool isPalindrome(int x) {
        long rev=0;
        int dup =x;
        while(x){
            rev = rev*10 + x%10;
            x = x/10;
        }
        if(dup<0)
            return false;
        return dup==int(rev);
    }
};