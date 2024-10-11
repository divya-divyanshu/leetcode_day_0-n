class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int rev = 0, n = x;
        while (n > 0) {
            int number = n % 10;
            rev = (rev * 10) + number;
            n /= 10;
        }

        return rev == x;
    }
};
