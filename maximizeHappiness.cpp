class Solution {
public:
    static bool comp(int a, int b){
        return a > b;
    }
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), comp);
        long long total = 0;
        int cnt = 0;
        for(int i = 0;i <k; i++){
            total += max(happiness[i]-cnt, 0);
            cnt++;
        }

        return total;
    }
};