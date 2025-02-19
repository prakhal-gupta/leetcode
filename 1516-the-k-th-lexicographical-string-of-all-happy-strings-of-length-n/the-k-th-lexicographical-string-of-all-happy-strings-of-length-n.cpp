class Solution {
public:
    string getHappyString(int n, int k) {
        string currentString = "";
        string result = "";
        int indexInSortedList = 0;
        generateHappyStrings(n, k, currentString, indexInSortedList, result);
        return result;
    }

private:
    void generateHappyStrings(int n, int k, string &currentString, int &indexInSortedList, string &result) {
        if (currentString.size() == n) {
            indexInSortedList++;
            if (indexInSortedList == k) result = currentString;
            return;
        }
        for (char currentChar = 'a'; currentChar <= 'c'; currentChar++) {
            if (currentString.size() > 0 && currentString.back() == currentChar)
                continue;
            currentString += currentChar;
            generateHappyStrings(n, k, currentString, indexInSortedList, result);
            if (result != "") return;
            currentString.pop_back();
        }
    }
};