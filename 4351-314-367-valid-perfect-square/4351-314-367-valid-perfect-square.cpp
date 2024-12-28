class Solution {
public:
    bool isPerfectSquare(int num) {
        int s =0;
        int e = num;
        long long int mid = s+(e-s)/2;    
        while(s<=e){        
            long long sqr = mid*mid;       
            if(sqr == num){
                return true;
            }
            else if(sqr < num){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
            mid = s+(e-s)/2;
        }
        return false;
    }
};