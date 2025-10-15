class Solution {
  public:
    bool fn(int n, int k, vector<int>&arr, vector<vector<int>>&dp){
        if(k == 0) return true;
        if( n == 0) return arr[n] == k;
        
        if(dp[n][k] != -1) return dp[n][k];
        
        bool take = false, notTake = false;
        
        if(arr[n] <= k) take = fn(n-1, k- arr[n], arr, dp);
        notTake = fn(n-1, k, arr, dp);
        
        return dp[n][k] = take|notTake;
        
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(sum+1, -1));
        return fn(n-1, sum, arr, dp);
        
    }
};