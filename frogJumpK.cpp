class Solution {
  public:
    int fun(vector<int>& arr, vector<int>& dp, int n, int k){
        if ( n == 0) return 0;
        if (dp[n] != -1) return dp[n];
        int minCost = INT_MAX;
        for (int i = 1; i <=k; i++){
            if ( n-i >= 0) {
                int cost = (fun(arr, dp, n-i, k)+ abs(arr[n] - arr[n-i]));
                minCost = min(minCost, cost);
            }
        }
        return dp[n] = minCost;
    }
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> dp(n,-1);
        dp[0] =0;
        return fun(arr,dp,n-1, k);
    }
};