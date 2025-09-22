class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int>mpp;
        for(auto it:nums) mpp[it]++;
        int maxi = INT_MIN;
        for(auto it:mpp) if(it.second>maxi) maxi = it.second;

        int cnt  = 0;
        for(auto it:mpp) if(it.second == maxi) cnt++;
        return cnt*maxi;
    }
};