class Solution {
  public:
    int fn(int ind, int W, vector<int>&val, vector<int>&wt, vector<vector<int>>&dp){
        if(ind == 0){
            if(wt[0] <= W) return val[0];
            else return 0;
        }
            
        if(dp[ind][W] != -1) return dp[ind][W];
            
        int nottake = 0 + fn(ind-1, W, val, wt, dp);
        int take = -1e9;
        if(wt[ind] <= W) take = val[ind] + fn(ind-1, W-wt[ind], val, wt, dp);
            
        return dp[ind][W] = max(take, nottake);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>>dp(n, vector<int>(W+1, -1));
        return fn(n-1, W, val, wt, dp);
        
    }
};