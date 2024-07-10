class Solution {
public:
    int minOperations(vector<string>& logs) {
        int folderDepth = 0;
        for (const auto& currentOperation : logs) {
            if (currentOperation == "../")
                folderDepth = max(0, folderDepth - 1);
            else if (currentOperation != "./")
                ++folderDepth;
        }
        return folderDepth;
    }
};