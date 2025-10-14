class Solution {
public:
    int fn(int n, int m, int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp){
        if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e8;
        if(i == n-1) {
            if( j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int maxi = -1e8;
        for(int dj1 = -1 ;dj1 <= 1; dj1++){
            for(int dj2 = -1 ;dj2 <= 1; dj2++){
                int temp = fn(n, m, i+1, j1+dj1, j2+dj2, grid, dp);
                if(j1 == j2) temp = temp + grid[i][j1];
                else temp = temp + grid[i][j1] + grid[i][j2];
                maxi = max(maxi, temp);
            }
            
        }
        dp[i][j1][j2] = maxi;
        return maxi;
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return fn(n, m, 0, 0, m-1, grid, dp);
    }
};