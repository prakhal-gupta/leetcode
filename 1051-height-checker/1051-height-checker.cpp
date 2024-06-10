class Solution {
    // Function to perform bubble sort on the input array.
    void bubbleSort(vector<int>& arr) {
        int n = arr.size();
        // Loop through the array for bubble sort passes.
        for (int i = 0; i < n - 1; ++i) {
            // Inner loop to compare and swap elements.
            for (int j = 0; j < n - i - 1; ++j) {
                // Compare and swap if elements are in the wrong order.
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

public:
    int heightChecker(vector<int>& heights) {
        // Sort the array using bubble sort.
        vector<int> sortedHeights = heights;
        bubbleSort(sortedHeights);

        int count = 0;
        // Loop through the original and sorted arrays.
        for (int i = 0; i < sortedHeights.size(); ++i) {
            // Increment count if elements at the same index differ.
            if (heights[i] != sortedHeights[i]) {
                count += 1;
            }
        }
        // Return the total count of differing elements.
        return count;
    }
};