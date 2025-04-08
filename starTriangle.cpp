void nStarTriangle(int n) {
    for (int i = 1; i <=n; i++){

        for (int k = 1; k <= n-i; k++){
            cout<<" ";
        }
        // starc
        for (int star = 1; star <= i*2 -1; star++){
            cout<<"*";
        }
        for (int k = 1; k <= n-i; k++){
            cout<<" ";
        }

        cout<<endl;


    }
}