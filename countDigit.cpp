class Solution {
  public:
    // Function to count the number of digits in n that evenly divide n
    int evenlyDivides(int n) {
        int cnt = 0;
        int temp = n;
        while (temp > 0){
            int dgt = temp%10;
            temp /= 10;
            if (dgt > 0){
                if (n % dgt ==  0) cnt++;
            }
        }
        return cnt;
    }
};