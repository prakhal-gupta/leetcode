class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> count(nums.size(), 0);
        vector<pair<int, int>> indexedNums;
        for (int i = 0; i < nums.size(); ++i) {
            indexedNums.push_back({nums[i], i});
        }
        mergeSort(indexedNums, count, 0, indexedNums.size() - 1);

        return count;
    }
    
    void mergeSort(vector<pair<int, int>>& nums, vector<int>& count, int left, int right) {
        if (left >= right) 
            return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, count, left, mid);
        mergeSort(nums, count, mid + 1, right);
        merge(nums, count, left, mid, right);
    }

    void merge(vector<pair<int, int>>& nums, vector<int>& count, int left, int mid, int right) {
        vector<pair<int, int>> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;

        while (i <= mid && j <= right) {
            if (nums[i].first > nums[j].first) {
                count[nums[i].second] += (right - j + 1);
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }
        while (i <= mid) {
            temp[k++] = nums[i++];
        }
        while (j <= right) {
            temp[k++] = nums[j++];
        }
        for (int idx = left, k = 0; idx <= right; ++idx, ++k) {
            nums[idx] = temp[k];
        }
    }
};
