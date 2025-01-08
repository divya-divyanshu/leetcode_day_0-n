class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int low = 0;
        int high = nums.size()-1;
        int mini = INT_MAX;

        while (low <= high){
            int mid = low + (high-low)/2;
            //left sorted
            if (nums[low] <= nums[mid]){
                mini = min(mini, nums[low]);
                low = mid+1;
            }
            // else right half is sorted
            else{
                mini = min (mini, nums[mid]);
                high = mid-1;
            }
        }

        return mini;
    }
};