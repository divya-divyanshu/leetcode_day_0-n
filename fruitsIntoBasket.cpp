class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int l = 0;
        int r = 0;
        int maxLen  = 0;
        unordered_map<int, int>mpp;
        int k = 2;

        while ( r < arr.size()){
            mpp[arr[r]]++;
            if (mpp.size() > k ) {
                mpp[arr[l]]--;
                if(mpp[arr[l]] == 0) mpp.erase(arr[l]);

                l++;
            }
          if(mpp.size() <= k){
            maxLen = max(maxLen , r-l+1);
          }
          r++;
        }
        return maxLen;
    }
};