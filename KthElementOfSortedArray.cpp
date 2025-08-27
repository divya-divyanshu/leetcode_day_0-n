class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n1 = a.size();
        int n2 = b.size();
        int i = 0;
        int j = 0;
        int cnt = 0;
        int ans = -1;
        while (i < n1 && j <n2){
            if (a[i] <= b[j]){
                cnt++;
                ans = a[i];
                i++;
                if (cnt == k) return ans;
            }
            else{
                cnt++;
                ans = b[j];
                j++;
                if (cnt == k) return ans;
            }
        }
        
        while (i < n1){
            cnt++;
            ans = a[i];
            i++;
            if (cnt == k) return ans;
        }
        
        while (j <n2){
            cnt++;
            ans = b[j];
            j++;
            if (cnt == k) return ans;
        }
        return -1;
    }
};