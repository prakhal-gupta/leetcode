class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adjacencyList[n];

        for(auto& flight : flights) {
            int fromCity = flight[0];
            int toCity = flight[1];
            int price = flight[2];

            adjacencyList[fromCity].push_back({toCity, price});
        }

        vector<int> prices(n, INT_MAX);
        queue<pair<int, pair<int, int>>> q;
        
        q.push({0, {src, 0}});
        prices[src] = 0;

        while(!q.empty()) {
            int currentCity = q.front().second.first;
            int currentPrice = q.front().second.second;
            int currentStops = q.front().first;
            
            q.pop();
            
            if(currentStops > k) continue;

            for(auto& neighbour : adjacencyList[currentCity]) {
                int neighbourCity = neighbour.first;
                int priceToNeighbourCity = neighbour.second;

                if(currentPrice + priceToNeighbourCity < prices[neighbourCity]) {
                    prices[neighbourCity] = currentPrice + priceToNeighbourCity;
                    q.push({currentStops + 1, {neighbourCity, prices[neighbourCity]}});
                }
            }
        }

        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};