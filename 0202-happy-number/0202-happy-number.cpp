class Solution {
public:
    long int new_n(long int m){
        long int n{0};
        while(m){
            long int temp = m%10;
            n += temp*temp;
            m/=10;
        }
    return n;
    }
    bool isHappy(int n) {
        long int m {n};
        unordered_map<long int,int> nums{};
        while(m!=1 && nums.count(m)==0){
            nums[m]++;
            m =  new_n(m);
        }
        return m==1;
    }
};