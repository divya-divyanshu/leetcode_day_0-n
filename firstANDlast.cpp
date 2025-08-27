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

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        int l = left(nums, target);
        int r = right(nums, target);

        return {l,r};
    }
};