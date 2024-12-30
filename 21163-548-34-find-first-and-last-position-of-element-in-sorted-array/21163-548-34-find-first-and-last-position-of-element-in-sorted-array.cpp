class Solution{
public:
    vector<int>searchRange(vector<int>&nums,int target){
        int first=findPosition(nums,target,true);
        int last=findPosition(nums,target,false);
        return{first,last};
    }
    
private:
    int findPosition(vector<int>&nums,int target,bool findFirst){
        int left=0,right=nums.size()-1,pos=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                pos=mid;
                if(findFirst)
                    right=mid-1;
                else
                    left=mid+1;
            } else if(nums[mid]<target)
                left=mid+1;
            else
            right=mid-1;
        }
        return pos;
    }
};