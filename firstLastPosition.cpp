class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        int low = 0;
        int high = nums.size() -1;
        int pos = -1;
        while (low <= high){
            int mid = (low + high) / 2;
            if (nums[mid] == target){
                pos = mid;
                break;
            }
            else if (nums[mid] < target) low = mid+1;
            else high = mid-1;
        }
        if (pos == -1){
            return {-1,-1};
        }
        int left = pos;
        int right = pos;
        while (true){
            if ((left - 1) >= 0){
                if (nums[pos] == nums[left -1]) left--;
                else break;
            }
            else break;
        }
        while (true){
            if ((right + 1) < nums.size()){
               if (nums[pos] == nums[right +1]) right++;
                else break; 
            }
            else break;
        }
        return {left, right};
    }
};