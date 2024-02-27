class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
    std::vector<bool> eaten(n, false); // Keeps track of whether a student has eaten or not
    int sandwichIndex = 0; // Index for iterating through sandwiches

    while (sandwichIndex < n) {
        bool satisfied = false; // Flag to indicate if any student can eat the current sandwich
        for (int i = 0; i < n; ++i) {
            if (!eaten[i] && students[i] == sandwiches[sandwichIndex]) {
                eaten[i] = true; // Mark the student as eaten
                satisfied = true; // Mark as satisfied
                break; // Move to the next sandwich
            }
        }
        if (!satisfied) {
            break; // No student can eat the current sandwich, so break the loop
        }
        sandwichIndex++;
    }

    return n - sandwichIndex;
    }
};