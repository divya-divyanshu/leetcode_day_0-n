class Solution {
public:
    int findNumbers(vector<int>& nums) {

        int NoNo = 0;
        for (int i = 0; i < nums.size(); i++){
            int n = nums[i];
            int cnt  = 0;

            while (n > 0){
                n = n/10;
                cnt++;
            }
            if (cnt % 2 == 0){
                NoNo++;
                cnt = 0;
            }
            else cnt = 0;
        }
        return NoNo;
        
    }
};