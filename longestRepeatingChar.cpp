class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r  =0;
        int maxlen  = 0;
        int maxf  =0;
        unordered_map<int, int> hss;
        while ( r < s.size()){
            hss[s[r] - 'A']++;
            maxf = max(maxf, hss[s[r] - 'A']);
            if ((r-l+1) - maxf > k){
                hss[s[l] - 'A']--;
                maxf = 0;
                l++;
            }
            if((r-l+1) - maxf <= k) maxlen = max(maxlen, r-l+1);

            r++;
        }
        return maxlen;
    }
};  
