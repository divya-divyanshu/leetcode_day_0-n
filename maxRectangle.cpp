class Solution {
public:
 vector<int> leftSmall(vector<int>& arr){
        vector<int> temp(arr.size());
        stack<int> st;
        for(int i  = 0;i < arr.size(); i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()) temp[i] =-1;
            else{
                temp[i] = st.top();
            }
            st.push(i);
        }
        return temp;
    }
    vector<int> rightSmall(vector<int>& arr){
        vector<int> temp(arr.size());
        stack<int> st;
        int n = arr.size();
        for(int i  = n-1;i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()) temp[i] = n;
            else{
                temp[i] = st.top();
            }
            st.push(i);
        }
        return temp;
    }
    int largestRectangleArea(vector<int>& arr) {
        vector<int> left = leftSmall(arr);
        vector<int> right = rightSmall(arr);
        int maxi = 0;
        for(int i = 0; i < arr.size(); i++){
            int area = arr[i] * (right[i]-left[i]-1);
            maxi = max(maxi, area);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> temp(n, vector<int> (m));

        for(int j = 0; j < m; j++) temp[0][j] = (mat[0][j]) - '0';
        for(int i  = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] - '0' == 1) {
                    temp[i][j] = (temp[i-1][j]) + 1;
                }
                else temp[i][j] = 0;
            }
        }

        int maxi = INT_MIN;

        for(int i  = 0;i < n; i++){
            int ans = largestRectangleArea(temp[i]);
            maxi = max(maxi, ans);
        }

        return maxi;

    }
};