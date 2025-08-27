class Solution {
  public:
  int left (vector<int> nums, int target){
        int low = 0;
        int high = nums.size() -1;
        int pos = -1;
        while (low <= high){
            int mid = (low + high) / 2;
            if (nums[mid] == target){
                pos = mid;
                high = mid-1;
            }
            else if (nums[mid] < target) low = mid+1;
            else if (nums[mid] > target) high = mid-1;
        }

        return pos;
    }

    int right (vector<int> nums, int target){
        int low = 0;
        int high = nums.size() -1;
        int pos = -1;
        while (low <= high){
            int mid = (low + high) / 2;
            if (nums[mid] == target){
                pos = mid;
                low = mid+1;
            }
            else if (nums[mid] < target) low = mid+1;
            else if (nums[mid] > target) high = mid-1;
        }

        return pos;
    }
    int countFreq(vector<int>& arr, int target) {
        int l = left(arr, target);
        int r = right(arr, target);
        if (l==-1 && r== -1) return 0;
        int cnt = (r-l)+1;
        return cnt;
    }
};