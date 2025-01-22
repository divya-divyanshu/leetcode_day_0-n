class Solution {
  public:
  int upperBound(vector<int> &arr, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;  
        }
    }
    return ans;
}

  int blackBox(vector<vector<int>> mat, int n ,int m, int x){
      int cnt = 0;
      for (int i = 0; i <n; i++){
          cnt += upperBound(mat[i], x, n);
      }
      return cnt;
  }
    int median(vector<vector<int>> &mat) {
        int low = INT_MAX;
        int high = INT_MIN;
        int n = mat.size();
        int m = mat[0].size();
        
        for (int i = 0; i <n; i++){
            low = min(low, mat[i][0]);
            high = max(high, mat[i][m-1]);
        }
        
        int req = (n*m)/2;
        while (low <= high){
            int mid = (low+high)/2;
            int smallEqual = blackBox(mat, n, m, mid);
            if (smallEqual <= req) low = mid+1;
            else high = mid-1;
        }
        return low;
    }
};