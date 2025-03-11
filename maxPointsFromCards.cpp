class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int sum = 0;
        int maxi = 0;
        int n  = cardPoints.size();
        for (int i  = 0; i < k; i++){
            sum += cardPoints[i];
        }
        maxi = sum;

        int r = n;
        int l = k;
        while ( l > 0){
            r--;
            l--;
            sum = sum - cardPoints[l] + cardPoints[r];
            maxi = max(maxi, sum);
        }

        return maxi;

    }
};