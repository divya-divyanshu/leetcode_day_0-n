class Solution {
  public:
    vector<int> twoOddNum(vector<int>& arr) {
        // code here
        long xorr = 0;
        for(int i = 0; i < arr.size(); i++) xorr ^= arr[i];
        int rightMost = xorr & ~(xorr -1);
        
        int od1 =0;
        int od2 =0;
        
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] & rightMost) od1 ^= arr[i];
            else od2 ^= arr[i];
        }
        if(od1 > od2) return {od1, od2};
        return {od2, od1};
    }
};