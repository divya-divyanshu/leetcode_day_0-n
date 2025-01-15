class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 0) return -1;
        if (nums.size() == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[nums.size()-1] != nums[nums.size()-2]) return nums[nums.size()-1];
        int low = 0;
        int high = nums.size()-1;

        while (low <= high){
            int mid = low + (high-low)/2;
            if (nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];
             
            else if (mid % 2 == 0){
                if (nums[mid+1] == nums[mid]) low = mid+1;
                else if (nums[mid-1] == nums[mid]) high = mid-1;
            }
            
            else if (mid % 2 == 1){
                if (nums[mid] == nums[mid-1]) low = mid+1;
                else if (nums[mid] == nums[mid+1]) high = mid-1;
            }
        }
        return -1;
    }
};