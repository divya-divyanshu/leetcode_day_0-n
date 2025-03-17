class Solution {
public:
    bool divideArray(vector<int>& nums) {
        // int xrr = 0;
        // for (int i = 0; i < nums.size(); i++) xrr = xrr^nums[i];

        // if (xrr == 0) return true;
        // return false;

        map<int, int>mpp;
        for (int i = 0;i<nums.size(); i++){
            mpp[nums[i]]++;
        }
        for(auto it:mpp){
            if (((it.second )%2) == 1) return false;
        }

        return true;
    }
};