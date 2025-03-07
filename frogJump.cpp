class Solution {
  public:
    int fun(vector<int>& arr, vector<int>&dp, int n){
        if (n == 0) return 0;
        
        if ( dp[n] != -1) return dp[n];
        
        int oneStep = fun(arr, dp, n-1) + abs(arr[n] - arr[n-1]);
        int twoStep = INT_MAX;
        if (n > 1) twoStep = fun(arr, dp, n-2) + abs(arr[n] - arr[n-2]);
        return dp[n] = min(oneStep, twoStep);
        
    }
    int minCost(vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        return fun(arr, dp , n-1); // bcoz n-1 is actuallly the last index of array
    }
};
