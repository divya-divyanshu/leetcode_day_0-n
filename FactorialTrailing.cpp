class Solution {
public:

    int trailingZeroes(int n) {
        int cnt = 0;
        int power5 = 5;
        while ( n >= power5){
            cnt += n/power5;
            power5 *= 5;
        }

        return cnt;
        
    }
};