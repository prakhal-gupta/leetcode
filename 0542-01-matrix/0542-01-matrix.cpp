class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if (mat.empty()) return {};
        
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    result[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            
            for (auto [dx, dy] : directions) {
                int ni = i + dx;
                int nj = j + dy;
                
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && result[ni][nj] > result[i][j] + 1) {
                    result[ni][nj] = result[i][j] + 1;
                    q.push({ni, nj});
                }
            }
        }
        
        return result;
    }
};