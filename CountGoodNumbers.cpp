class Solution {
public:
    long long fp(long long a, long long b){
        if(b == 0) return 1;
        long long half = fp(a, b/2);
        long long res = half*half;
        if(b % 2 == 1) return (a*res)%1000000007;
        return res%1000000007;
    }
    int countGoodNumbers(long long n) {
        long long odd = n/2;
        long long even = n-odd;
        return (fp(5, even)*fp(4, odd))%1000000007;
    }
};