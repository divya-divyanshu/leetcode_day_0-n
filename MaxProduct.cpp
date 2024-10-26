class Solution {
public:
    int maxProduct(vector<int>& arr) {

    int n = arr.size();
    int pref = 1, suff = 1;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++){

        if (pref == 0) pref = 1;
        if (suff == 0) suff = 1;

        pref = pref * arr[i];
        suff = suff * arr[n-i-1];

        maxi = max (maxi, max(pref, suff));
    }
    return maxi;
    }
};