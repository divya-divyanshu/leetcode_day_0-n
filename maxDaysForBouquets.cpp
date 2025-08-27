class Solution {
public:
    bool possible (vector<int> bloomDay, int day,int k, int m){
        int cnt = 0;
        int boq = 0;
        for (int i = 0; i < bloomDay.size(); i++){
            if (bloomDay[i] <= day) cnt++;
            else{
                boq += (cnt/k);
                cnt = 0;
            }
        }

        boq += (cnt / k);

        if ( boq >= m) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for (int i = 0; i < bloomDay.size(); i++){
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }
        if ( bloomDay.size() < (long long)m*k) return -1;
        int low = mini;
        int high = maxi;
        int ans = -1;
        while (low <= high){
            int mid = low + (high-low)/2;
            if  ( possible (bloomDay, mid, k, m) == true){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        return ans;
    }
};