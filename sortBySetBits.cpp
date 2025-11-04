class Solution {
public:
    static bool comp(int num1, int num2){
        int a = __builtin_popcount(num1);
        int b = __builtin_popcount(num2);
        if(a == b) return num1 < num2;
        return a<b;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};
