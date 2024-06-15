class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects(n);
        for (int i = 0; i < n; ++i)
            projects[i] = {capital[i], profits[i]};
        sort(projects.begin(), projects.end());
        priority_queue<int> max_heap;
        int project_index = 0;
        for (int i = 0; i < k; ++i) {
            while (project_index < n && projects[project_index].first <= w) {
                max_heap.push(projects[project_index].second);
                project_index++;
            }
            if (max_heap.empty())
                break;
            w += max_heap.top();
            max_heap.pop();
        }
        return w;
    }
};