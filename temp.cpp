#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<vector<int>> mat(3, vector<int>(3));
    vector<vector<int>> preSum(3, vector<int>(3));

    for (int i = 0; i < 3; i++){
        for (int j = 0; j <3; j++){
            cin>>mat[i][j];
        }
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j <3; j++){
            int left  =0;
            if (j-1 >= 0) left = preSum[i][j-1];
            int top = 0;
            if (i-1 >= 0) top = preSum[i-1][j];
            int diag = 0;
            if ((i-1 >=0) && (j-1 >= 0)) diag = preSum[i-1][j-1];

            preSum[i][j] = (mat[i][j] + left+ top) - diag;
        }
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout<<preSum[i][j]<<" ";
        }
        cout<<endl;
    }

    
    return 0;
}