// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int> hpx;

        for(int i = 0; i < arr.size(); i++){
            if(hpx.size() < k) hpx.push(arr[i]);

            else if(hpx.top() > arr[i]){
                hpx.pop();
                hpx.push(arr[i]);
            }
        }
        return hpx.top();
    }
};