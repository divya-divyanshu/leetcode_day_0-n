class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
          int floor = -1;
          int ceil = -1;

          for (int i = 0; i < arr.size(); i++){
              if (arr[i] > floor && arr[i] <= x) floor = arr[i];
              if (ceil == -1){
                  if (arr[i] >= x) ceil = arr[i];
              }
              else if (arr[i] < ceil && arr[i] >= x) ceil = arr[i];
          }
          return {floor, ceil};
    }
};