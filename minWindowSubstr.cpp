class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hss (256, 0);

        int l = 0;
        int r = 0;
        int minlen = INT_MAX;
        int sindex = -1;
        int cnt  = 0;
        int n = s.size();
        int m = t.size();

          if (m > n) return "";


        for(char c: t) hss[c]++;

        while( r < n){
            if(--hss[s[r]] >= 0){
                cnt++;
            }
            // hss[s[r]]--;
            while(cnt == m){
                if( r-l+1 < minlen) {
                    minlen = r-l+1;
                    sindex = l;
                }
                // hss[s[l]]++;
                if(++hss[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }

        return sindex == -1 ? "" : s.substr(sindex, minlen);
    }
};