
class Solution {
  public:

    vector<int> count_NGE(vector<int> &arr, vector<int> &ind) {
        // code here
        vector<int>ans;
        for (int k  = 0; k < ind.size(); k++){
            int idx = ind[k];
            int cnt = 0;
            for(int i =idx+1; i < arr.size(); i++){
                if(arr[i] > arr[idx]) cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};