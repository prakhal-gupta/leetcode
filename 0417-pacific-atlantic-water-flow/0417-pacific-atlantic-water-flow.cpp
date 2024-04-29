class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& canReachOcean, int i, int j, int prevHeight) {
        int m = heights.size();
        int n = heights[0].size();
        
        if (i < 0 || i >= m || j < 0 || j >= n || canReachOcean[i][j] || heights[i][j] < prevHeight) {
            return;
        }
        canReachOcean[i][j] = true;
        dfs(heights, canReachOcean, i + 1, j, heights[i][j]);
        dfs(heights, canReachOcean, i-1, j, heights[i][j]);
        dfs(heights, canReachOcean, i, j+1, heights[i][j]);
        dfs(heights, canReachOcean, i, j-1, heights[i][j]);

    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty()) return {};
        
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<bool>> canReachPacific(m, vector<bool>(n, false));
        vector<vector<bool>> canReachAtlantic(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; ++i) {
            dfs(heights, canReachPacific, i, 0, INT_MIN); 
            dfs(heights, canReachAtlantic, i, n - 1, INT_MIN);
        }
        for (int j = 0; j < n; ++j) {
            dfs(heights, canReachPacific, 0, j, INT_MIN);
            dfs(heights, canReachAtlantic, m - 1, j, INT_MIN);
        }
        
        vector<vector<int>> result;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (canReachPacific[i][j] && canReachAtlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
};