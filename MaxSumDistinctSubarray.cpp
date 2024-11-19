class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        unordered_map<int, int> mpp;
        long long usum = 0, sum = 0;

        for (int i = 0; i < k; i++) {
            sum += nums[i];
            mpp[nums[i]]++;
        }

        if (mpp.size() == k) {
            usum = sum;
        }

        
        for (int i = k; i < n;i++){
            
            sum -= nums[i - k];
            mpp[nums[i - k]]--;

            if (mpp[nums[i - k]] == 0) {
                mpp.erase(nums[i - k]);
            }



            sum += nums[i];
            mpp[nums[i]]++;

            if (mpp.size() == k){
                usum = max(usum, sum);
            }
        }

        return usum;
        
    }
};