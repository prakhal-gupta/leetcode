class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        int freshCount = 0;
        
        queue<pair<int, int>> rotten;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++freshCount;
                } else if (grid[i][j] == 2) {
                    rotten.push({i, j});
                }
            }
        }
        
        int minutes = 0;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!rotten.empty() && freshCount > 0) {
            int size = rotten.size();
            for (int i = 0; i < size; ++i) {
                auto [x, y] = rotten.front();
                rotten.pop();
                
                for (auto [dx, dy] : directions) {
                    int nx = x + dx;
                    int ny = y + dy;
                    
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2; 
                        rotten.push({nx, ny});
                        --freshCount;
                    }
                }
            }
            ++minutes;
        }
        
        return freshCount == 0 ? minutes : -1;
    }
};