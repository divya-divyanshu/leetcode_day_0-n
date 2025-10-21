class Solution {
public:
    void pushi(vector<int>& nums, int el, int &ind, int t){
        if(t == 1){
            nums[ind] = el;
            ind++;
        }
        else{
            nums[ind] = el;
            ind++;
            nums[ind] = el;
            ind++;
        }
    }
    int removeDuplicates(vector<int>& nums) {
        map<int, int>mpp;
        for(auto it:nums) mpp[it]++;
        int cnt = 0;
        int k = 0;
        for(auto it:mpp){
            if(it.second == 1){
                cnt++;
                pushi(nums, it.first, k, 1);
            }
            else if(it.second >= 2){
                cnt += 2;
                pushi(nums, it.first, k, 2);
            }
        }
        return cnt;
    }
};