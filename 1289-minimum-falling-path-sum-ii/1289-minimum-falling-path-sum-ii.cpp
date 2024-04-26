class Solution {
public:
    array<int, 2> findmin2(vector<int>& row){
        int x0=INT_MAX, x1=INT_MAX;
        for(int x: row){
            if (x<x0) 
                x1=exchange(x0, x);
            else if(x<x1) x1=x;
        }
        return {x0, x1};
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        
        for(int i=1; i<n; i++){
            auto min2=findmin2(grid[i-1]);
            for(int j=0; j<n; j++){
                if (grid[i-1][j]==min2[0])
                    grid[i][j]+=min2[1];
                else
                    grid[i][j]+=min2[0];
            }
        }
        return *min_element(grid[n-1].begin(), grid[n-1].end());
    }
};