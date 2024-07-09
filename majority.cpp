class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int el;
        int cnt = 0;

        for ( int i = 0 ; i < nums.size(); i++ ){
            
            if (cnt == 0){
                cnt =1;
                el = nums[i];
            }
            else if ( el ==  nums[i]) cnt++;
            else cnt--;
        }

        // verifying the answer is not supposed as it is already mentioned in the    question that majority element always exists in the array.
    return el;
        
    }
};