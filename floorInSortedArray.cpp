lass Solution {
  public:

    int findFloor(vector<int>& arr, int k) {
        if (k < arr[0] || k > arr[arr.size()-1]) return -1;
        if (k == arr[0]) return 0;
        if (k == arr[arr.size()-1]) return arr.size()-1;

        int low = 0;
        int high = arr.size()-1;
        while (low <= high){
            int mid = (low + high) /2;
            if (arr[mid] == k) return mid;
            else if ( k > arr[mid]){
                low = mid+1;
                if (arr[low] > k) return mid;
            }
            else{
                high = mid-1;
                if (arr[high] < k) return high;
            }
        }
        
        return -1;
    }
};