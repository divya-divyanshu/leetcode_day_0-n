class Solution {
public:
    int beautySum(string s) {
        int n =  s.size();
        int ans = 0;
        for (int i = 0; i <n; i++){
            map<char,int> mpp;
            for (int j = i; j<n;j++){
                mpp[s[j]]++;

                int maxi = 0;
                int mini = INT_MAX;

                for (auto a:mpp){
                    maxi = max(maxi, a.second);
                    mini = min(mini, a.second);
                }

                ans += (maxi-mini);
            }
        }

        return ans;
        
    }
};