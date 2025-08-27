class Solution {
public:
    int trap(vector<int>& arr) {
        int l = 0;
        int r = arr.size()-1;
        int lmax = 0;
        int rmax = 0;
        int sum = 0;

        while(l < r){
            // always run smaller
            if(arr[l] < arr[r]){
                if(lmax > arr[l]) {
                    sum += lmax - arr[l];
                }
                lmax = max(lmax, arr[l]);
                l++;
            }
            else{
                if(rmax > arr[r]){
                    sum += rmax - arr[r];
                }
                rmax = max(rmax, arr[r]);
                r--;
            }
        }

        return sum;
    }
};