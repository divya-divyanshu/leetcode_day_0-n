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
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int total = 0;
        for(auto &it:arr) total += it;
        
        if(total - d < 0) return 0;
        if(((total-d) % 2 ) == 1) return 0;
        vector<vector<int>>dp(arr.size(), vector<int>((total-d)/2 + 1, -1));
        return fn(arr.size()-1, (total-d)/2, arr, dp);
        
    }
};  