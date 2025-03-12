class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int negMax = 0;
        int posMax = 0;
        for (int i  = 0; i<nums.size(); i++){
            if (nums[i] == 0) continue;
            else if (nums[i] < 0) negMax++;
            else posMax++;
        }

        return max(negMax, posMax);
    }
};