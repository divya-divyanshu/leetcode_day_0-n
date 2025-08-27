void symmetry(int n) {
    for (int i = 1; i <= n; i++ ){
        // star
        for (int j =1; j <= i; j++){
            cout<<"* ";
        }

        // space
        for (int k = 1; k <= (n-i)*2; k++){
            cout<<" ";
        }

        // star
        for (int j =1; j <= i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    for (int i = n-1; i > 0; i--){
         // star
        for (int j =1; j <= i; j++){
            cout<<"* ";
        }

        // space
        for (int k = 1; k <= (n-i)*2; k++){
            cout<<" ";
        }

        // star
        for (int j =1; j <= i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}