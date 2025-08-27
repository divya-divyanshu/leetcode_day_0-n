class Solution {
  public:
    int fn(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int n, int m){
        if (j1 < 0 || j1 > m -1 || j2 < 0 || j2 > m -1) return -1e8;
        if (i ==n-1){
            if (j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        
        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int maxi = -1e8;
        for (int dj1 =  -1; dj1 <= 1; dj1++){
            for (int dj2 = -1; dj2 <= 1; dj2++){
                if (j1 == j2){
                    int temp = grid[i][j1] + fn(i+1, j1+dj1, j2+dj2, grid, dp, n,m);
                    maxi = max(maxi, temp);
                }
                else {
                    int temp = grid[i][j1] + grid[i][j2] + fn(i+1, j1+dj1, j2+dj2, grid, dp, n,m);
                    maxi = max(maxi, temp);
                }
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return fn(0,0, m-1, grid, dp, n, m);
    }
};