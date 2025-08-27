class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int, int>mpp;
        for(int i  = 0; i < banned.size(); i++){
            mpp[banned[i]]++;
        }
        int cnt = 0;
        int sum = 0;
        for(int i = 1; i <=n; i++){
            if(!(mpp.find(i) != mpp.end())){
                sum += i;
                if(sum > maxSum) return cnt;

                cnt++;
            }
        }
        return cnt;
    }
};