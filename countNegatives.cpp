class Solution {
public:
    int fn(vector<int>arr, int m){
        int low = 0;
        int high = m-1;

        while (low <= high){
            int mid = (low+high) / 2;
            if (arr[mid] < 0) high = mid-1;
            else if (arr[mid] >= 0) low = mid+1;
        }
        return (m-low);
    }
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0 ; i < n; i++){
            cnt += fn(grid[i], m);
        }

        return cnt;
    }
};