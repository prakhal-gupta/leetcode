class Solution {
public:
    void markUnguarded(int row, int col, vector<vector<int>>& grid) {
        for (int r = row - 1; r >= 0; r--) {
            if (grid[r][col] == 3 || grid[r][col] == 2) break;
            grid[r][col] = 1;
        }
        for (int r = row + 1; r < grid.size(); r++) {
            if (grid[r][col] == 3 || grid[r][col] == 2) break;
            grid[r][col] = 1;
        }
        for (int c = col - 1; c >= 0; c--) {
            if (grid[row][c] == 3 || grid[row][c] == 2) break;
            grid[row][c] = 1;
        }
        for (int c = col + 1; c < grid[row].size(); c++) {
            if (grid[row][c] == 3 || grid[row][c] == 2) break;
            grid[row][c] = 1;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (const auto& guard : guards)
            grid[guard[0]][guard[1]] = 2;
        for (const auto& wall : walls)
            grid[wall[0]][wall[1]] = 3;
        for (const auto& guard : guards)
            markUnguarded(guard[0], guard[1], grid);
        int count = 0;
        for (const auto& row : grid) {
            for (const auto& cell : row) {
                if (cell == 0) count++;
            }
        }
        return count;
    }
};