void nStarDiamond(int n) {
    //upper tri 
    for (int i = 1; i <=n; i++){

        for (int k = 1; k <= n-i; k++){
            cout<<" ";
        }
        // star
        for (int star = 1; star <= i*2 -1; star++){
            cout<<"*";
        }
        for (int k = 1; k <= n-i; k++){
            cout<<" ";
        }

        cout<<endl;
    }


    // lower tri

    for (int i = n; i > 0; i--){

        for (int k = 1; k <= n-i; k++){
            cout<<" ";
        }
        // star
        for (int star = 1; star <= i*2 -1; star++){
            cout<<"*";
        }
        for (int k = 1; k <= n-i; k++){
            cout<<" ";
        }

        cout<<endl;
    }
}