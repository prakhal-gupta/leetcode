class Solution {
public:
    int reverseBits(uint32_t n) {
        int ans=0;
        for(; n; n&=(n-1)){
            ans+=1<<(31-countr_zero(n));
        }
        return ans;
    }
};