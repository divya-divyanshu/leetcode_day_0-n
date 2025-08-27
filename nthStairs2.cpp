class Solution {
public:
    int climbStairs(int n) {

        if (n == 0) return 1;
        if (n == 1) return 1;

        int prev = 1;
        int prev2  = 1;

        // vector<int> dp(n+1, 0);
        // dp[0] = 1;
        // dp[1] = 1;

        for (int i = 1; i < n; i++){
            // int left = dp[i-1];
            // int right = dp[i-2];

            int fs = prev;
            int ss = prev2;

            // dp[i] = left + right;

            int curi = fs + ss;

            prev2 = prev;
            prev = curi;
        }

        // return dp[n];
        return prev;
    }
};