// User function Template for C++

class Solution {
  public:
    void sieve() {}

    vector<int> findPrimeFactors(int n) {

        // Write your code here
        if(n < 2) return {};
        vector<int>primes(n+1, 0);
        for(int i = 2; i <= n; i++) primes[i] =1;

        for(int i = 2; i*i <=n; i++){
            if(primes[i] == 1){
                for(int j = i*i; j <= n; j+=i){
                    primes[j] = 0;
                }
            }
        }
        vector<int>ans; 
        for(int i = 2; i < primes.size(); i++) 
            if(primes[i] != 0){
                while(n % i == 0) {  
                    ans.push_back(i);
                    n /= i;
                }
            }
                
        
        return ans;
    }
};