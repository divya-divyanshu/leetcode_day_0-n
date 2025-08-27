class Solution {
public:
    string addStrings(string num1, string num2) {
        unordered_map<char, int>mpp;
        for(char c = '0'; c <= '9'; c++ ){
            mpp[c] = c - '0';
        }

        string ans = "";

        int i = num1.size()-1;
        int j = num2.size()-1;

        int carry = 0;
        while(i >=0 && j >=0){
            int a = mpp[num1[i]];
            int b = mpp[num2[j]];

            int sum = a+b+carry;
            int dig = sum%10;
            carry = sum/10;
            ans += (dig + '0');
            i--;
            j--;
        }
        while(i >=0){
            int a = mpp[num1[i]];
            int sum = a+carry;
            int dig = sum%10;
            carry = sum/10;
            ans += (dig + '0');
            i--;
        }
        while(j >=0){
            int a = mpp[num2[j]];
            int sum = a+carry;
            int dig = sum%10;
            carry = sum/10;
            ans += (dig + '0');
            j--;
        }
        if(carry > 0) ans += (carry + '0');

        reverse(ans.begin(), ans.end());

        return ans;
    }
};