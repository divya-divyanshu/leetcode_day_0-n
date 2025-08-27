class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<int> st;
        int l = 0;
        int r = 0;
        int n = s.size();
        int len = 0;
        while ( r < n){
            while (st.find(s[r]) != st.end()){
                st.erase(s[l]);
                l++;
                len = max(len, r-l+1);
            }
            st.insert(s[r]);
            len = max(len, r-l+1);
            r++;
        }
        return len;
    }
};