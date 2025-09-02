
class Solution {
  public:
  
  bool isCBT(int arr[], int i, int n){
      
    if(i >= n) return true;
    
    if(arr[i] == -1 ) return false;
    
    bool left = isCBT(arr, 2*i+1, n);
    bool right = isCBT(arr, 2*i+2, n);
    return left&&right;

  }
  
  bool isHeap(int arr[], int i, int n){
      if(i >=n) return true;

      int left = 2*i+1;
      int right = 2*i+2;
      bool l = true,r = true;
      if(left < n) l = (arr[left] <= arr[i]);
      if(right < n) r = (arr[right] <= arr[i]);
    //   return l&&r&&isHeap(arr, i+1, n);
    return l && r && isHeap(arr, left, n) && isHeap(arr, right, n);

  }
  
    bool isMaxHeap(int arr[], int n) {
        // Your code goes here
        return isCBT(arr, 0, n) && isHeap(arr, 0, n);
    }
};