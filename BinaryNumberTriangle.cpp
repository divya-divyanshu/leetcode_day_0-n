void nBinaryTriangle(int n) {
    int k;
    for (int i = 1; i <= n; i++){
       if ( i % 2 == 1) k = 1;
       else k = 0;
        for (int j = 1; j <= i ; j++){
            cout<<k<<" ";
            k = k == 1?0:1;
        }
        cout<<endl;
    }
}