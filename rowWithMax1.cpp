class Solution {
  public:
  
    int noOfOnes(vector<int> mat){
        int n = mat.size();
        int low = 0;
        int high = n-1;
        int ans = n;
        while (low <= high){
            int mid = (low+high)/2;
            if (mat[mid] == 1){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();
        int m = arr[0].size();
        int cnt_max = -1;
        int index = -1;
        for (int i = 0; i <n; i++){
            int cnt_ones =  m - noOfOnes(arr[i]);
            if (cnt_ones > cnt_max){
                cnt_max = cnt_ones;
                index = i;
            }
        }
        return index;
    }
};