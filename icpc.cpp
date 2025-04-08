#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximizeArraySum(vector<int>& a, int k) {
    int n = a.size();
    int sum = 0;

    // Sort array in descending order to maximize sum by reducing largest pairs
    sort(a.rbegin(), a.rend());

    // Process the array to reduce pairs of elements larger than k
    for (int i = 0; i < n - 1; ++i) {
        // Try to reduce pairs while both elements are greater than k
        while (a[i] > k && a[i + 1] > k) {
            a[i]--;
            a[i + 1]--;
        }
    }

    // Calculate the final sum
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }

    return sum;
}

int main() {
    int T;
    cin >> T;
    
    vector<int> results;
    results.reserve(T);  // Reserve space for efficiency
    
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        results.push_back(maximizeArraySum(a, k));
    }

    // Output all results
    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}
