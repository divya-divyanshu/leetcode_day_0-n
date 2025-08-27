class Solution {
public:
int func(vector<int> arr, int mid){
    int cnt = 1;
    int val = 0;

    for (int i = 0; i < arr.size(); i++){
        if (val + arr[i] <= mid){
            val += arr[i];
        }
        else{
            cnt++;
            val = 0;
            val = arr[i];
        }
    }
    return cnt;
}
    int splitArray(vector<int>& nums, int k) {
        if (k > nums.size()) return -1;
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low <= high){
            int mid = low + (high-low)/2;
            int subArray = func(nums, mid);
            if (subArray > k) low = mid+1;
            else high = mid-1;
        }
        return low;
    }
};