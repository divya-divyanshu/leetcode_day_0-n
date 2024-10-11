class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ans;

        for(int i =0; i<nums1.size(); i++){
 
            int next = -1;

            int j = 0;
            while (nums2[j] != nums1[i]) {
                j++;
            }

            for (int k = j+1; k<nums2.size(); k++){
                if(nums2[k] > nums1[i]) {
                    next=nums2[k];
                    break;
                }
            }
            ans.push_back(next);
        }

        return ans;
        
    }
};