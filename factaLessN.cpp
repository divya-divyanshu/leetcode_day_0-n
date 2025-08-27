class Solution {
  public:
  long long facta(int n, vector<long long> &dp){
      if ( n <= 1) return 1;
      if (dp[n] != -1) return dp[n];
      return dp[n] = n*facta(n-1, dp);
      
  }
    vector<long long> factorialNumbers(long long n) {
        vector<long long>ans;
        vector<long long> dp(21, -1);
        dp[0] = 1;
        for (long long i = 1; i <=n; i++){
            long long x = facta(i, dp);
            if ( x > n) break;
            ans.push_back(x);
        }
        return ans;
    }
};