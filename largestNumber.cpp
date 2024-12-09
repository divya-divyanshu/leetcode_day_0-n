class Solution {
public:

 
    string largestNumber(vector<int>& nums) {

        bool flag = true;
        vector<string> str;
        for (int i = 0; i <nums.size();i++){
            if (nums[i] > 0) flag = false;
            str.push_back(to_string(nums[i]));
        }

        if (flag) return "0";


        sort(str.begin(), str.end(), [](const string& s1, const string& s2){
             return (s1 + s2) > (s2 + s1);
        });

        string ans = "";
        for (int i = 0; i < str.size();i++){
            ans += str[i];
        }
        return ans;
    }
};