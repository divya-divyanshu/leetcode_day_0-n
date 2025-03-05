class Solution {
  public:
    bool armstrongNumber(int n) {
        int armNo = 0;
        int temp =n;
        while ( temp > 0){
            int d = temp%10;
            temp = temp/10;
            d = d*d*d;
            armNo += d;
        }
        
        if (armNo == n) return true;
        return false;
    }
};