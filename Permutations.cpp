class Solution {
public:
    void calcPermutation(vector<int> nums, vector<int>& newPerm, vector<int>& freq, vector<vector<int>>& ans){
        if (newPerm.size() == nums.size()){
            ans.push_back(newPerm);
            return;
        }
        for (int i = 0; i < nums.size(); i++){
            if (!freq[i]){
                freq[i] =1;
                newPerm.push_back(nums[i]);
                calcPermutation(nums, newPerm, freq, ans);
                freq[i] = 0;
                newPerm.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        // a map to keep track of taken elements in newPermutation 
        // being calculated, which is here newPerm
        vector<int> freq (nums.size(), 0);

        vector<int> newPerm;
        calcPermutation(nums, newPerm, freq, ans);
        
        return ans;
        
    }
};