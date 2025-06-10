class Solution {
public:
    static bool comp(int a,int b){
        return a>b;
    }
    int findSize(int temp){
        int s = 0;
        while(temp > 0){
            s++;
            temp = temp/10;
        }
        
        return s;
        
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<int>st;
        int maxLen  =0;
        for(int i = 0; i < arr1.size(); i++){
            int temp = arr1[i];
            while(temp > 0){
                st.insert(temp);
                temp /= 10;
            }
        }

        sort(arr2.begin(), arr2.end(), comp);
        for(auto it:arr2){
            int temp = it;
            while(temp > 0){
                if(st.find(temp) != st.end()) {
                    maxLen = max (maxLen,findSize(temp));
                    break;
                }
                temp /= 10;
            }
        }

        return maxLen;
        
    }
};