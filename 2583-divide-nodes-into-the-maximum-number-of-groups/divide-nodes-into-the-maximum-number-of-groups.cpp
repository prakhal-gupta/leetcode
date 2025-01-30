class Solution {
public:
    int magnificentSets(int n, vector<vector<int>> &edges) {
        vector<vector<int>> adjList(n);
        for (auto edge : edges) {
            adjList[edge[0] - 1].push_back(edge[1] - 1);
            adjList[edge[1] - 1].push_back(edge[0] - 1);
        }
        vector<int> colors(n, -1);
        for (int node = 0; node < n; node++) {
            if (colors[node] != -1) continue;
            colors[node] = 0;
            if (!isBipartite(adjList, node, colors)) return -1;
        }
        vector<int> distances(n);
        for (int node = 0; node < n; node++)
            distances[node] = getLongestShortestPath(adjList, node, n);
        int maxNumberOfGroups = 0;
        vector<bool> visited(n, false);
        for (int node = 0; node < n; node++) {
            if (visited[node]) continue;
            maxNumberOfGroups += getNumberOfGroupsForComponent(adjList, node, distances, visited);
        }
        return maxNumberOfGroups;
    }

private:
    bool isBipartite(vector<vector<int>> &adjList, int node, vector<int> &colors) {
        for (int neighbor : adjList[node]) {
            if (colors[neighbor] == colors[node]) return false;
            if (colors[neighbor] != -1) continue;
            colors[neighbor] = (colors[node] + 1) % 2;
            if (!isBipartite(adjList, neighbor, colors)) return false;
        }
        return true;
    }

    int getLongestShortestPath(vector<vector<int>> &adjList, int srcNode, int n) {
        queue<int> nodesQueue;
        vector<bool> visited(n, false);
        nodesQueue.push(srcNode);
        visited[srcNode] = true;
        int distance = 0;
        while (!nodesQueue.empty()) {
            int numOfNodesInLayer = nodesQueue.size();
            for (int i = 0; i < numOfNodesInLayer; i++) {
                int currentNode = nodesQueue.front();
                nodesQueue.pop();
                for (int neighbor : adjList[currentNode]) {
                    if (visited[neighbor]) continue;
                    visited[neighbor] = true;
                    nodesQueue.push(neighbor);
                }
            }
            distance++;
        }
        return distance;
    }

    int getNumberOfGroupsForComponent(vector<vector<int>> &adjList, int node, vector<int> &distances,
                                      vector<bool> &visited) {
        int maxNumberOfGroups = distances[node];
        visited[node] = true;
        for (int neighbor : adjList[node]) {
            if (visited[neighbor]) continue;
            maxNumberOfGroups = max(maxNumberOfGroups, getNumberOfGroupsForComponent(
                                        adjList, neighbor, distances, visited));
        }
        return maxNumberOfGroups;
    }
};