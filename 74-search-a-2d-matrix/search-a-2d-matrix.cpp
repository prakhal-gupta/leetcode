class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size() * matrix[0].size();
        int cols = matrix[0].size();
        int s = 0, e = n - 1;
        int mid = s + (e - s) / 2;
        while (s <= e) {
            int rowIndex = mid / cols;
            int colIndex = mid % cols;
            if (matrix[rowIndex][colIndex] == target)
                return true;
            else if (matrix[rowIndex][colIndex] > target)
                e = mid - 1;
            else
                s = mid + 1;
            mid = s + (e - s) / 2;
        }
        return false;
    }
};