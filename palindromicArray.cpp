class Solution {
  public:
    bool isPalindrome(int num){
        string str = to_string(num);
        if (str.size() == 1) return true;
        int i = 0;
        int j = str.size()-1;
        while (i < j){
            if (str[i] != str[j]) return  false;
            i++;
            j--;
        }
        return true;
    }
    bool isPalinArray(vector<int> &arr) {
        for (int i  = 0; i < arr.size(); i++){
            if (isPalindrome(arr[i])) continue;
            return false;
        }
        return true;
    }
};
