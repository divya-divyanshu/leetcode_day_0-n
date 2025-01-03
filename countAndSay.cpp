class Solution {
public:
    string compressor(int n){
        if (n == 1){
            return to_string(1);
        }
        string tempans = compressor(n-1);
        int nn = tempans.size();
        string ans = "";
       
        char curi = tempans[0];
        int cnt = 1;
        for (int i = 1; i < nn; i++){
            if (tempans[i] == curi) cnt++;
            else{
                ans += to_string(cnt);
                ans += curi;
                
                curi = tempans[i];
                cnt = 1;
            }
        }
        ans += to_string(cnt);
        ans += curi;
        
        return ans;
    }

    string countAndSay(int n) {
        string ans = compressor(n);
        return ans;
        
    }
};