class Solution {
public:
    int kthFactor(int n, int k) {
        int cnt = 0;
        int i;
        for (i = 1; i<=n; i++){
            if (n % i == 0) cnt++;
            if (cnt == k) break;
        }
        if (cnt == k) return i;
        else return -1;
    }
};