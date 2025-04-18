class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
   
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++) maxi = max(maxi, nums[i]);
        int low = 1;
        int high = maxi;
        // int sum =  INT_MAX;
        int ans = -1;

        while (low <= high){
            int mid = low + (high-low)/2;
            int tempSum = 0;
            for (int i = 0; i < nums.size();i++){
                tempSum += (nums[i] + mid - 1) / mid;
            }
            if (tempSum > threshold) {
                low = mid+1;
            }

            else{
                ans = mid;
                high = mid-1;
            }
            // else if (tempSum <= threshold){
            //     if (tempSum < sum){
            //         sum = tempSum;
            //         ans = mid;
            //     }
            //     high = mid-1;
            // }
        }

        return ans;
        
    }
};