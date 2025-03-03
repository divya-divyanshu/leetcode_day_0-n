void alphaHill(int n) {
    // Write your code here.
    for (int i = 1 ; i <= n; i++){
        //space
        for (int j = 1; j <= n-i; j++){
            cout<<" ";
        }
        //letter

        char ch = 'A';
          int breakp = i;
          for(int j=1;j<=2*i-1;j++){
              
              cout<<ch<<" ";
              if(j < breakp) ch++;
              else ch--;
          }

        //space
        for (int j = 1; j <= n-i; j++){
            cout<<" ";
        }

        cout<<endl;
    }
}