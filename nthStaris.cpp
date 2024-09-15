class Solution {
public:

    
    int climbStairs(int ind, vector<int>& dp) {

        if (ind == 0) return 1;
        if (ind == 1) return 1;

        if (dp[ind] != -1) return dp[ind];

        int left = climbStairs(ind -1, dp);
        int right = climbStairs(ind -2, dp);

        return dp[ind] = left + right;
        
    }

    int climbStairs(int ind){
        vector<int> dp(ind+1, -1);
        return climbStairs(ind, dp);
    }
};