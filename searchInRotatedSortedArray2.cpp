class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int n = nums.size();
        int high = n-1;
        while (low <= high){
            
            int mid = low + (high-low)/2;

            if (nums[mid] == target) return true;

            // trimming down the array
            if (nums[low] == nums[mid] && nums[mid] == nums[high]){
                low = low+1;
                high = high-1;
                continue;
            }


            // right is sorted
            if (nums[mid] <= nums[high]){
                if (target <= nums[high] && target > nums[mid])  low = mid+1;
                else high = mid-1;
            }
            
            // left is sorted
            else{
                if (target < nums[mid] && target >= nums[low]) high = mid-1;
                else low = mid+1;
            }
        }
        return false;
        
    }
};