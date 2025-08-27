class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        // int right = 0;
        // int left = m-1;

        // while (left >= 0 && right < n){
        //     if (nums1[left] > nums2[right]){
        //         int temp = nums1[left];
        //         nums1[left] = nums2[right];
        //         nums2[right] = temp;
        //         left--;
        //         right++;
        //     }

        //     else{
        //         break;
        //     }
        // }

        // sort(nums1.begin(), nums1.end());
        // sort(nums2.begin(), nums2.end());

        // for (int i = 0; i < n; i++){
        //     nums1[m+i] = nums2[i];
        // }

        // above is erroneous

        for (int i = 0; i < n; i++){
            nums1[m+i] = nums2[i];
        }

        sort(nums1.begin(), nums1.end());


        
    }
};