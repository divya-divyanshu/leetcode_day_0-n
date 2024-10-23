class Solution {
  public:
  
  int merge(vector<int>& arr, int low, int mid, int high){
      vector<int> temp;
      int left = low;
      int right = mid+1;
      
      int cnt = 0;
      
      while (left <= mid && right <= high){
          if (arr[left] <= arr[right]){
              temp.push_back(arr[left]);
              left++;
          }
          // right is smaller
          else{
              temp.push_back(arr[right]);
              cnt += (mid-left+1);
              right++;
          }
          
      }
      
      while (left <= mid){
          temp.push_back(arr[left]);
          left++;
      }
      while (right <= high){
          temp.push_back(arr[right]);
          right++;
      }
      
      for (int i = low; i <= high; i++){
          arr[i] = temp[i-low];
      }
      
      return cnt;
  }
  
  
  int mergeSort(vector<int>& arr, int low, int high){
      int cnt  = 0;
      if (low >= high) return cnt;
      int mid = (low+high) /2;
      
      cnt += mergeSort(arr, low, mid);
      cnt += mergeSort(arr, mid+1, high);
      cnt += merge(arr, low, mid, high);
      
      return cnt;
  }
  
  
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        return mergeSort(arr, 0, n-1);
    }
};