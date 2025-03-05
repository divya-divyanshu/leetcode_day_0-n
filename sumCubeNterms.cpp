class Solution {
  public:
  int summa(int n){
      if ( n == 1) return 1;
      return ((n*n*n) + summa(n-1));
  }
    int sumOfSeries(int n) {
        // code here
        return summa(n);
    }
};