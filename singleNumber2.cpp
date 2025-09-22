class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int bind = 0; bind < 32; bind++){
            int cnt = 0;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] & (1 << bind)) cnt++;
            }
            if(cnt % 3 == 1) ans = ans | (1 << bind);
        }
        return ans;
    }
};