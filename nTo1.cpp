class Solution {
  public:
  void printa(int n){
         if (n == 1){
             cout<<n<<" ";
             return;
         }
         cout<<n<<" ";
         return printa(n-1);
        
    }
    void printNos(int N) {
        // code here
        printa(N);
    }
};