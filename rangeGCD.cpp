// User function template in C++

// st : segment tree
// n : size of the given array
// l and r : range to find gcd i.e L and R respectively

class Solution {
  public:
    int Fgcd(int a, int b){
        if(b == 0) return a;
        return Fgcd(b, a % b);
    }

    int query(int idx, int low, int high, int l, int r, int *st){
        if(l <= low && high <= r) return st[idx];
        if(r < low || l > high) return 0;
        int mid = low + (high - low)/2;
        
        int left = query(2*idx+1, low, mid, l, r, st);
        int right = query(2*idx+2, mid+1, high, l, r, st);
        
        return Fgcd(left, right);
    }
    // Function to find gcd of given range.
    int findRangeGcd(int l, int r, int st[], int n) {
        // code here
        return query(0, 0, n-1, l, r, st);
        
    }
    
    void update(int idx, int low, int high, int i, int nv, int *arr, int *st){
        if(low == high){
            arr[i] = nv;
            st[idx] = nv;
            return;
        }
        
        int mid = low + (high-low)/2;
        
        if( i <= mid) update(2*idx+1, low, mid, i, nv, arr, st);
        else update(2*idx+2, mid+1, high, i, nv, arr, st);
        
        st[idx] = Fgcd(st[2*idx+1], st[2*idx+2]);
    }

    // Function to update a value in input array and segment tree.
    void updateValue(int index, int new_val, int *arr, int st[], int n) {
        
        // code here
        update(0, 0, n-1, index, new_val, arr, st);
    }
};