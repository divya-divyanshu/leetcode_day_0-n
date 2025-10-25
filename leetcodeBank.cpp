class Solution {
public:
    int totalMoney(int n) {
        int cnt = 0;
        int sum  = 0;
        while(n > 7){
            sum += 28 + 7*cnt;
            n -= 7;
            cnt++;
        }
        sum += ((n*(n+1))/2) + (n*cnt);

        return sum;
    }
};