class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int el1 = INT_MIN;
        int el2 = INT_MIN;
        int cnt1 = 0;
        int cnt2 = 0;
        
        for (int i = 0; i < nums.size(); i++){

            if (cnt1 == 0 && el2 != nums[i]){
                cnt1++;
                el1 = nums[i];
            }
            else if (cnt2 == 0 && el1 != nums[i]){
                cnt2++;
                el2 = nums[i];
            }

            else if (el1 == nums[i]) cnt1++;
            else if (el2 == nums[i]) cnt2++;

            else {
                cnt1--;
                cnt2--;
            }

        }

        // manual check

        vector<int> ls;
        int mini = (nums.size())/3 + 1;
        int c1 =0, c2= 0;

        for (int i= 0; i < nums.size(); i++){
            if (nums[i] == el1) c1++;
            if (nums[i] == el2) c2++;
        }

        if (c1 >= mini) ls.push_back(el1);
        if (c2 >= mini) ls.push_back(el2);

        return ls;
        
    }
};