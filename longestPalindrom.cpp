class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        int freq[128] = {0};

        int ans  = 0;

        for (int i  = 0; i< n; i++){
            freq[s[i] ]++;
        }

        for (int i = 0; i < 128; i++){
            if (freq[i] % 2 == 0) ans += freq[i];
            else{
                ans += (freq[i] / 2)*2;
            }
        }
        if (ans == n) return ans;

        return ans+1;

    }
};