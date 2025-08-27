class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int low = 0;
        int n = arr.size();
        int high = n-1;
        int mini = INT_MAX;
        int ind = -1;

        while (low <= high){
            int mid = low + (high-low)/2;
            //left is sorted
            if (arr[low] <= arr[mid]){
                if (arr[low] <= mini){
                    mini = arr[low];
                    ind = low;
                }
                low = mid+1;
                
            }
            // else right is sorted
            else{
                if (arr[mid] <= mini){
                    mini = arr[mid];
                    ind = mid;
                }
                high = mid-1;
            }
        }
        return ind;
    }
};
