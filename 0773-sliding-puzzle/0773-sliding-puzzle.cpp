class Solution {
private:
    vector<vector<int>> directions = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {3, 5, 1}, {4, 2}};

public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string startState;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++)
                startState += to_string(board[i][j]);
        }
        unordered_map<string, int> visited;
        dfs(startState, visited, startState.find('0'), 0);
        return visited.count("123450") ? visited["123450"] : -1;
    }

private:
    void dfs(string state, unordered_map<string, int>& visited, int zeroPos, int moves) {
        if (visited.count(state) && visited[state] <= moves)
            return;
        visited[state] = moves;
        for (int nextPos : directions[zeroPos]) {
            swap(state[zeroPos], state[nextPos]);
            dfs(state, visited, nextPos,moves + 1);
            swap(state[zeroPos],state[nextPos]);
        }
    }
};