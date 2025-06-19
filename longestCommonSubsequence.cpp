class Solution {
public:
    int fnTab(int n, int m, string& text1, string& text2, vector<vector<int>>&dp){
        for(int i = 1; i <=n; i++){
            for(int j = 1; j <= m; j++){
                if(text1[i-1] == text2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    int fn(int i, int j, int n, int m, string& text1, string& text2, vector<vector<int>>&dp){
        if( i >= n || j >=m)  return 0;
        if(text1[i] == text2[j]){
            return dp[i][j] = 1 + fn(i+1, j+1, n, m, text1, text2, dp);
        }
        if(dp[i][j] != -1) return dp[i][j];
        int a = fn(i+1, j, n, m, text1, text2, dp);
        int b = fn(i, j+1, n, m, text1, text2, dp);

        return dp[i][j] = max(a, b);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        // vector<vector<int>>dp(n, vector<int>(m, -1));
        // return fn(0, 0, n, m, text1, text2, dp);
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        return fnTab(n, m, text1, text2, dp);
    }
};