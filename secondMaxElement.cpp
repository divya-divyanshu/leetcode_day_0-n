class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        int sMax = -1;
        int max = -1;
        int n = arr.size();
        
        for (int i = 0; i <n; i++){
            
            
            if (max < arr[i]){
                sMax = max;
                max = arr[i];
            }
            if (arr[i] < max && arr[i] >= sMax) sMax = arr[i];
            
        }
        return sMax;
    }
};