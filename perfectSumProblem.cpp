class Solution {
  public:
    int fn(int ind, int sum, vector<int>&arr, vector<vector<int>>&dp){
        if(ind == 0) {
            if(sum == 0 && arr[0] == 0) return 2;
            else if(sum == 0 || arr[0] == sum) return 1;
            else return 0;
        }
        
        if(dp[ind][sum] != -1) return dp[ind][sum];
        
        int pick = 0;
        if(arr[ind] <= sum) pick = fn(ind-1, sum-arr[ind], arr, dp);
        int notPick = fn(ind-1, sum, arr, dp);
        
        return dp[ind][sum] = pick+notPick;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(target+1, -1));
        
        return fn(n-1, target, arr, dp);
    }
};