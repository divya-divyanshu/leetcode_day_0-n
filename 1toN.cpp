class Solution {
  public:
    void printa(int n){
         if (n == 1){
             cout<<n<<" ";
             return;
         }
         
         printa(n-1);
         cout<<n<<" ";
         return;
        
    }
    void printNos(int n) {
        printa(n);
    }
};