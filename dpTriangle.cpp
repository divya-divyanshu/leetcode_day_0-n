class Solution {
public:
    int fn(int i, int j,int n, vector<vector<int>>& dp, vector<vector<int>>& a){
        if ( i == n-1) return a[n-1][j];
        if (dp[i][j] != -1) return dp[i][j];
        int down = a[i][j] + fn(i+1, j, n, dp, a);
        int diagonal = a[i][j] + fn(i+1,j+1, n, dp, a);

        return dp[i][j] = min(down, diagonal);
    }
    int minimumTotal(vector<vector<int>>& a) {

        int n = a.size();
      

        vector<vector<int>> dp(n, vector<int>(n, -1));

        int res = fn(0, 0,  n, dp, a);

        return res;


    }
};