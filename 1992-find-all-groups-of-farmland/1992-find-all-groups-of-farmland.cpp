class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<bool>> visited(land.size(), vector<bool>(land[0].size(), false));
        vector<vector<int>> ans;
        for (int row = 0; row < land.size(); row++) {
            for (int col = 0; col < land[0].size(); col++) {
                if (land[row][col] && !visited[row][col]) {
                    int bottomRow = row, rightCol = col;
                    DFS(land, visited, row, col, bottomRow, rightCol);
                    ans.push_back({row, col, bottomRow, rightCol});
                }
            }
        }
        return ans;
    }

private:
    int dirs[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    bool isWithinFarm(int x, int y, int N, int M) {
        return x >= 0 && x < N && y >= 0 && y < M;
    }
    
    void DFS(vector<vector<int>>& land, vector<vector<bool>>& visited, int x, int y, int& bottomRow, int& rightCol) {
        visited[x][y] = true;
        bottomRow = max(bottomRow, x);
        rightCol = max(rightCol, y);
        for (auto dir : dirs) {
            int newX = x + dir[0], newY = y + dir[1];
            if (isWithinFarm(newX, newY, land.size(), land[0].size()) && !visited[newX][newY]
                    && land[newX][newY]) {
                DFS(land, visited, newX, newY, bottomRow, rightCol);
            }
        }
    }    
};
