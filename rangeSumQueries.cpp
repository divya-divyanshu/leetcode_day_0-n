class NumMatrix {
public:
    vector<vector<int>>premtx;
    NumMatrix(vector<vector<int>>& matrix) {
        
        int n= matrix.size();
        int m = matrix[0].size();
        
        premtx.resize(n, vector<int>(m));

        int sum = 0;
        for(int i  = 0; i < m; i++){
            sum  += matrix[0][i];
            premtx[0][i] = sum;
        }

        sum  = 0;
        for(int i  = 0; i < n; i++){
            sum += matrix[i][0];
            premtx[i][0] = sum;
        }


        for(int i = 1; i <n; i++){
            for(int j = 1; j < m; j++){
                premtx[i][j] = (matrix[i][j]+premtx[i-1][j]+premtx[i][j-1]) - premtx[i-1][j-1];
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int top = 0;
        if(row1-1 >= 0) top = premtx[row1-1][col2];
        int left = 0;
        if(col1-1>=0) left = premtx[row2][col1-1];

        int common = 0;
        if(row1-1 >=0 && col1-1 >=0) common = premtx[row1-1][col1-1];
        return (premtx[row2][col2] - top - left + common);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */