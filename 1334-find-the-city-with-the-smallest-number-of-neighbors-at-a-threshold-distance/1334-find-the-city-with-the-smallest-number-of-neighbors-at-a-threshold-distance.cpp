class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adjacencyList(n);
        vector<vector<int>> shortestPathMatrix(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++)
            shortestPathMatrix[i][i] = 0;
        for (const auto& edge : edges) {
            int start = edge[0];
            int end = edge[1];
            int weight = edge[2];
            adjacencyList[start].emplace_back(end, weight);
            adjacencyList[end].emplace_back(start, weight);
        }
        for (int i = 0; i < n; i++)
            dijkstra(n, adjacencyList, shortestPathMatrix[i], i);
        return getCityWithFewestReachable(n, shortestPathMatrix, distanceThreshold);
    }

    void dijkstra(int n, const vector<vector<pair<int, int>>>& adjacencyList, vector<int>& shortestPathDistances, int source) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> priorityQueue;
        priorityQueue.emplace(0, source);
        fill(shortestPathDistances.begin(), shortestPathDistances.end(), INT_MAX);
        shortestPathDistances[source] = 0;

        while (!priorityQueue.empty()) {
            auto [currentDistance, currentCity] = priorityQueue.top();
            priorityQueue.pop();
            if (currentDistance > shortestPathDistances[currentCity]) continue;
            for (const auto& [neighborCity, edgeWeight] : adjacencyList[currentCity]) {
                if (shortestPathDistances[neighborCity] > currentDistance + edgeWeight) {
                    shortestPathDistances[neighborCity] = currentDistance + edgeWeight;
                    priorityQueue.emplace(shortestPathDistances[neighborCity],neighborCity);
                }
            }
        }
    }

    int getCityWithFewestReachable( int n, const vector<vector<int>>& shortestPathMatrix, int distanceThreshold) {
        int cityWithFewestReachable = -1;
        int fewestReachableCount = n;
        for (int i = 0; i < n; i++) {
            int reachableCount = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (shortestPathMatrix[i][j] <= distanceThreshold) reachableCount++;
            }
            if (reachableCount <= fewestReachableCount) {
                fewestReachableCount = reachableCount;
                cityWithFewestReachable = i;
            }
        }
        return cityWithFewestReachable;
    }
};