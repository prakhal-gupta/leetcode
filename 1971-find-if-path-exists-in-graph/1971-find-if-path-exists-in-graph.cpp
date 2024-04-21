class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Using vector instead of unordered_map for faster access
        vector<vector<int>> graph(n);
        for(auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);
        visited[source] = true;
        
        while(!q.empty()) {
            int v = q.front();
            q.pop();

            if(v == destination) // Destination reached
                return true;

            for(int neighbor : graph[v]) {
                if(!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        
        return false;
    }
};
