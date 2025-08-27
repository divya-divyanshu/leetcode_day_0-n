class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> postDist(n);
        set<int>st;
        for(int i = n-1; i >= 0; i--){
            postDist[i] = st.size();
            st.insert(nums[i]);
        }
        vector<int> ans(n);
        st.clear();

        for(int i = 0; i < n; i++){
            st.insert(nums[i]);
            ans[i] = st.size() - postDist[i];
        }
        return ans;
    }
};