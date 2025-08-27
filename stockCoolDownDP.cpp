class Solution {
public:
    int fn(int i, bool flag, vector<int>& prices, vector<vector<int>>&dp){
        int n = prices.size();
        if(i >= n) return 0;

        int profit = 0;

        if(dp[i][flag] != -1) return dp[i][flag];

        if(flag == true){ // TO BUY
            int buy = -prices[i] + fn(i+1, false, prices, dp);
            int notBuy = fn(i+1, true, prices, dp);
            profit = max(buy, notBuy);
        }
        else{ // TO SELL
            int sell = prices[i] + fn(i+2, true, prices, dp);
            int notSell = fn(i+1, false, prices, dp);
            profit = max(sell, notSell);
        }
        return dp[i][flag] = profit;

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));
        return fn(0, true, prices, dp);
    }
};