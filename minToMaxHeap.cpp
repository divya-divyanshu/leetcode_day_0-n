// User function Template for C++

class Solution {
  public:
  
    void heapify(vector<int> &arr, int n, int ind){
        int largest = ind;
        int left = 2*ind+1;
        int right = 2*ind+2;
        if(left < n && arr[left] > arr[largest]) largest = left;
        if(right < n && arr[right] > arr[largest]) largest = right;
        if(largest != ind){
            swap(arr[largest], arr[ind]);
            heapify(arr, n, largest);
        }
    }

    void convertMinToMaxHeap(vector<int> &arr, int n) {
        for(int i  = n/2-1; i >=0 ; i--) heapify(arr, n, i);
    }
};
