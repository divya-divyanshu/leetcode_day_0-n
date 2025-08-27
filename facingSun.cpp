class Solution {
  public:
    // Returns count buildings that can see sunlight
         int fn(vector<int> arr){
 
        int cnt = 1;
        int maxi = arr[0];
        for(int  i = 1; i < arr.size(); i++){
            if(arr[i]  == maxi || arr[i] < maxi) continue;
    
 
            cnt++;
            if(arr[i] > maxi) maxi = arr[i];
        }
        return cnt;
    }
    
    int countBuildings(vector<int> &height) {
        // code here
        return fn(height);
    }
};