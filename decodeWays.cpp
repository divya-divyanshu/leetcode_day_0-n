class Solution {
public:
    ////BOTTOM UP - SPACE OPTIMISATION
    int fn(string& s, int n){
        int a = 1, b = 0, cur = 0;
        for(int i = n-1; i >=0; i--){
            cur = 0;
            if(s[i] != '0'){
                cur += a;
                if(i+2 <= n){
                    if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))
                    cur += b;
                }
            }
            b =a;
            a = cur;
        }
        return cur;
    }
        
    ////BOTTOM - UP USING DP
    // int fn(string& s, int n, vector<int>& dp){
    //     dp[n] = 1;
    //     for(int i = n-1; i >=0; i--){
    //         int a = 0, b = 0;
            
    //         if(s[i] != '0'){
    //             a = dp[i+1];

    //             if(i+2 <= n){
    //                 if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))
    //                     b = dp[i+2];
    //             }
    //         }
    //         dp[i] = a+b;
    //     }
    //     return dp[0];
    // }

    // // top down - dp array
    // int fn(string& s,int i, int n, vector<int>& dp){
    //     if(i == n) return 1;
    //     if(s[i] == '0') return 0;
    //     if(dp[i] != -1) return dp[i];
    //     int oneD = 0, twoD = 0;
    //     oneD = fn(s, i+1, n, dp);
    //     if(i+1 < n){
    //         if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')){
    //             twoD = fn(s, i+2, n, dp);
    //         }
    //     }
    //     return dp[i] = oneD+twoD;
    // }
    int numDecodings(string s) {
        
        if(s[0] == '0') return 0;
        int n = s.size();
        // TOP - DOWN
        // vector<int>dp(n+1, -1);
        // return fn(s, 0, n, dp);


        // BOTTOM UP- ;
        // vector<int>dp(n+1, 0);
        // return fn(s, n, dp);

        //BOTTOM UP - SPACE OPTIMISATION
        return fn(s, n);
    }
};