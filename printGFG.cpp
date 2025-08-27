class Solution {
  public:
  void printa(int n){
      if ( n == 0) return;
      cout<<"GFG ";
      return printa(n-1);
  }
    void printGfg(int N) {
        // Code here
        printa(N);
    }
};