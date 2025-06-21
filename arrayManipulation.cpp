long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long long>arr(n+2, 0);
    for(auto it:queries){
        int a = it[0];
        int b = it[1];
        int k = it[2];
        
        arr[a] += k;
        arr[b+1] -= k;
    }
    long long sum =0;
    for(int i =0; i <=n; i++){
        sum += arr[i];
        arr[i] = sum;
        
    }
    long long maxi = LLONG_MIN;
    for(auto it:arr) maxi = max(maxi, it);
    return maxi;
}