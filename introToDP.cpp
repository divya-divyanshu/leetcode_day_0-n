class Solution {
  public:
    const int mod = 1000000007;
    long long int fun(vector<long long>&dp, int n){
        if ( n <= 1) return n;
        if (dp[n] != -1) return dp[n];
        return dp[n] = (fun(dp, n-1) + fun(dp, n-2))% mod;
    }
    long long int topDown(int n) {
        vector<long long>dp(n+1, -1);
        return fun(dp, n);
    }
    long long int bottomUp(int n) {
        // code here
        if ( n == 0) return 0;
        if ( n == 1) return 1;
        long long prev2 = 0;
        long long prev = 1;
        for (int i =2; i <= n; i++){
            long long curi = (prev+prev2)%mod;
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
};