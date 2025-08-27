class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long zero1 = 0;
        long long zero2 = 0;
        long long sum1 = 0;
        long long sum2 = 0;

        for (int  i = 0; i < nums1.size(); i++){
            if(nums1[i] == 0) zero1++;
            
            sum1+=nums1[i];
        }
        for (int  i = 0; i < nums2.size(); i++){
            if(nums2[i] == 0) zero2++;
            
            sum2+=nums2[i];
        }


        sum1 += zero1;
        sum2 += zero2;

        if(sum1 < sum2 && zero1 == 0 || sum2 < sum1 && zero2 == 0) return -1;
        return max(sum1, sum2);


        return -1;
    }
};