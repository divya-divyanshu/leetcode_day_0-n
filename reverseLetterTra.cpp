void nLetterTriangle(int n) {
    for (int i = 0; i  < n; i++){
        char cr = 'A';
        for (int j = 0; j < n-i ; j++){
            cout<<cr<<" ";
            cr++;
            
        }
        cout<<endl;
    }
}