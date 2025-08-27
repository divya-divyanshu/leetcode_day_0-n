class Solution {
  public:
    int divisors(int n){
        int sum = 0;
        for (int i = 1; i <= n; i++){
            if (n % i == 0) sum+=i;
        }
        return sum;
    }
    int sumOfDivisors(int n) {
        // Write Your Code here
        int sum  = 0;
        for (int i = 1; i <=n; i++){
            sum += divisors(i);
        }
        return sum;
    }
};
