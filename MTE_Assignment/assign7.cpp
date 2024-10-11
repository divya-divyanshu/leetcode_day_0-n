class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        int n = nums.size();
        set<int> st;
        for (int i = 0; i <n; i++){
            int index = abs(nums[i]);
            if (nums[index -1] < 0)  st.insert(index);
            else  nums[index-1] *= -1;
        }

        vector<int> ans;

        for (auto it = st.begin(); it != st.end(); ++it) ans.push_back(*it);

        return ans;
    }
};