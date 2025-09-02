class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int>mpp;
        for(int i  = 0; i < arr1.size(); i++){
            mpp[arr1[i]]++;
        }
        vector<int>ans;
        for(int i = 0; i < arr2.size(); i++){
            int cnt = mpp[arr2[i]];
            for(int k = 0; k < cnt; k++) ans.push_back(arr2[i]);
            mpp.erase(arr2[i]);
        }

        vector<int>leftOvers;
        for(auto it:mpp){
            int cnt = it.second;
            for(int k = 0; k < cnt; k++) leftOvers.push_back(it.first);
        }
        sort(leftOvers.begin(), leftOvers.end());
        for(auto it:leftOvers) ans.push_back(it);
        return ans;
    }
};