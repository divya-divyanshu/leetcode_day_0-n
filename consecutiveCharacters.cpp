class Solution {
public:
    int maxPower(string s) {
        int cnt= 1;
        int maxi =1;
        int n = s.size();
        for (int i = 1; i < n; i++){
            if (s[i] == s[i-1]) cnt++;
            else cnt = 1;

            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};