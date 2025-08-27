class Solution {
  public:
    int minimumEnergy(vector<int>& a, int n) {
        vector<int>dp(n, 0);
        
        dp[0] = 0;
        int ss = INT_MAX;
        
        for (int i = 1 ; i < n ; i++){
            int fs = dp[i-1] + abs ( a[i] - a[i-1]);
            if (i > 1) ss = dp[i-2] + abs ( a[i] - a[i-2]);
            
            dp [i] = min(ss, fs);
        }
        
        return dp[n-1];
        
    }
    
};