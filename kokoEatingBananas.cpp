class Solution {
public:
    long long hourFn(vector<int> piles, int perHour){
        long long hours = 0;
        for (int i = 0; i < piles.size(); i++){
            hours +=  ceil ( (double) piles[i] / (double) perHour);
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = -1;
        for (int i = 0; i < piles.size(); i++){
            high = max (high, piles[i]);
        }
        int k = INT_MAX;
        while (low <= high){
            int mid = low + (high-low)/2;
            long long temp = hourFn(piles, mid);
            if (temp <= h){
                high = mid-1;
                k = min(k, mid);
            }
            else low = mid+1;
        }
        return k;
    }
};