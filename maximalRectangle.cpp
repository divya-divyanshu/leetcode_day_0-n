class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        stack<int>st;
        int maxi = 0;
        for(int i  = 0;i < arr.size(); i++){
            while(!st.empty () && arr[st.top()] > arr[i]){
                int el = arr[st.top()];
                st.pop();
                int nse = i;
                int pse = st.empty()?-1:st.top();
                maxi = max(maxi, (el*(nse-pse-1)));
            }
            st.push(i);
        }
        while(!st.empty()){
            int el = arr[st.top()];
            st.pop();
            int nse = n;
            int pse = st.empty()?-1:st.top();
            maxi = max(maxi, (el*(nse-pse-1)));
        }

        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>psum(n,vector<int>(m));

        for(int j  = 0; j < m; j++){
            int sum = 0;
            for(int i = 0; i < n; i++){
                if(mat[i][j] == '1') sum++;
                else sum = 0;
                psum[i][j] = sum;
            }
        }

        int maxi = 0;

        for(int i = 0; i <n; i++){
            maxi = max(maxi, largestRectangleArea(psum[i]));
        }
        return maxi;
    }
};