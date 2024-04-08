class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
    std::vector<bool> eaten(n, false);
    int sandwichIndex = 0;

    while (sandwichIndex < n) {
        bool satisfied = false;
        for (int i = 0; i < n; ++i) {
            if (!eaten[i] && students[i] == sandwiches[sandwichIndex]) {
                eaten[i] = true;
                satisfied = true;
                break;
            }
        }
        if (!satisfied) {
            break;
        }
        sandwichIndex++;
    }

    return n - sandwichIndex;
    }
};