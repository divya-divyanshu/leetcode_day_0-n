class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int sum = 0;
        int maxLen = 0;
        map<int, int>preSum;
        
        for (int i = 0; i < arr.size(); i++){
            sum += arr[i];
                
            if (sum == k){
                maxLen = max(maxLen, i+1);
            }
            
            int rem = sum - k;
            
            if (preSum.find(rem) != preSum.end()){
                int len = i - preSum[rem];
                maxLen = max(maxLen, len);
            }
            
            if (preSum.find(sum) == preSum.end()){
                preSum[sum] = i;
            }
        }
        return maxLen;
    }
};