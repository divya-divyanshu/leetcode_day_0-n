class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        long long ans  = 0;
        for(int i  =0; i < arr.size(); i++){
            int mini = INT_MAX;
            int maxi = INT_MIN;
            for(int j = i; j < arr.size(); j++){
                mini = min(mini, arr[j]);
                maxi = max(maxi, arr[j]);
                ans+= (maxi - mini);
            }
        }
        return ans;
    }
};