class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n = arr.size();
        vector<string> distinctStrings;
        for (int i = 0; i < n; i++) {
            string currentString = arr[i];
            bool isDistinct = true;
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                if (arr[j] == currentString) {
                    isDistinct = false;
                    break;
                }
            }
            if (isDistinct)
                distinctStrings.push_back(currentString);
        }
        if (distinctStrings.size() < k)
            return "";
        return distinctStrings[k - 1];
    }
};