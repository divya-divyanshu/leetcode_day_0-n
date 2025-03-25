//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int fn(int day, vector<vector<int>>&arr, int last, int no_task, vector<vector<int>>&dp){
        //BASE CASE
        if (day == 0){
            int maxi = 0;
            for (int i = 0; i <no_task ; i++){
                dp[day][i] = arr[day][i];
                if ( i != last){
                    dp[day][i] = arr[day][i];
                    maxi = max(maxi, arr[0][i]);
                }
            }
            return maxi;
        }
        
         
            if (dp[day][last] != -1) return dp[day][last];
         
        
        int maxi = 0;
        
        for (int i = 0; i < no_task; i++){
            if (last != i){
                maxi = max(maxi,  arr[day][i] + fn(day-1, arr, i, no_task, dp));
            }
        }
        
        return dp[day][last] = maxi;
        
    }
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int day = arr.size();
        int task = arr[0].size();
        
        vector<vector<int>> dp(day, vector<int>(task+1, -1));
        
        return fn(day-1, arr, task, task, dp);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends