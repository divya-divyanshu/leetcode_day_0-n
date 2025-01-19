// 1 - success 
// 0 - below m
// 2 - above m
int powerfn(int m, int mid, int n){
    long long ans =1;
    for (int i = 1; i<=n; i++){
        ans *= mid;
        if (ans > m ) return 2;
    }
    if (ans == m ) return 1;
    return 0;
}

class Solution {
  public:
    int nthRoot(int n, int m) {
        int low = 1;
        int high = m;
        
        while (low <= high){
            int mid = low + (high-low)/2;
            int temp = powerfn(m, mid, n);
            if (temp == 1) return mid;
            else if ( temp == 0) low = mid+1;
            else high = mid-1;
        }
        return -1;
    }
};