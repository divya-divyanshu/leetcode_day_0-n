class Solution {
public:

    bool check(vector<int>& a) {
        int k =0;
        int n = a.size();
        int i;
        for (i = 0; i <n-1; i++){
            if (a[i] > a[i+1]){
                k = i+1;
                break;
            }
            
        }
        if ( k == 0) return true;

        for (int j = k; j < n ;j++){
            if (a[(k+n) %n] > a[(k+n+1) % n]) {
                return false;
            }
            k++;
        }
        return true;
        
    }
};