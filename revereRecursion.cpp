class Solution {
  public:
  void rev(vector<int>& arr, int l , int r){
      if ( l >= r) return;
      swap(arr[l], arr[r]);
      rev(arr, l+1, r-1);
  }
    void reverseArray(vector<int> &arr) {
        // code here
        int l = 0;
        int r = arr.size()-1;
        rev(arr, l, r);
    }
};