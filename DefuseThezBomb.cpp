class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {

        int n = code.size();
        vector<int> ans(n, 0);  

        if ( k == 0 ) return ans;

        for (int i = 0; i <n; i++){
            int sum = 0;
            if (k > 0){
                int m = i+1;
                for (int j = 0; j<k;j++){
                    sum += code[m%n];
                    m++;
                }

            }

            else if (k < 0){
                int m = i-1;
                for (int j = 0;j < abs(k);j++){
                    sum += code[(m+n)%n];
                    m--;
                }
            }

             ans[i] = sum;

        }

        return ans;
        
    }
};