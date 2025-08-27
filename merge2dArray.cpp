class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int rm1 = nums1.size();
        int rm2 = nums2.size();
        int r1 = 0;
        int r2 = 0;
 
        vector<vector<int>>ans;

        while (r1 < rm1 && r2 < rm2){
            if (nums1[r1][0] < nums2[r2][0]){
                ans.push_back( {nums1[r1][0], nums1[r1][1]} );
                r1++;
            }
            else if (nums1[r1][0] > nums2[r2][0]){
                ans.push_back( {nums2[r2][0], nums2[r2][1]} );;
                r2++;
            }
            else {
                ans.push_back( {nums1[r1][0], (nums1[r1][1] + nums2[r2][1])} );
                r1++;
                r2++;
            }
 
        }

        while (r1 < rm1){
            ans.push_back( {nums1[r1][0], nums1[r1][1]} );
            r1++;
        }
        while (r2 < rm2){
            ans.push_back( {nums2[r2][0], nums2[r2][1]} );;
            r2++;
        }

        return ans;
    }
};