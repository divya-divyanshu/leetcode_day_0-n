class Solution {
  public:
    bool isEven(int n) {
        // code here
        int res = n & 1;
        if(res == 0) return true;
        return false;
    }
};