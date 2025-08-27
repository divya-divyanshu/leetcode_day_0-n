class Solution {
public:
    int Power(int mid,int num){
        long long ans = (long long)mid*mid;
    
        if (ans == num) return 1; // equal
        else if (ans > num) return 2; // greater
        return 0; // lesser
    }
    bool isPerfectSquare(int num) {
        int low = 1;
        int high = num;
        while (low <= high){
            int mid = low + (high-low)/2;
            if (Power(mid, num) == 1) return true;
            else if ( Power (mid, num) == 2){
                high = mid-1;
            }
            else low = mid+1;
        }
        return false;
    }
};