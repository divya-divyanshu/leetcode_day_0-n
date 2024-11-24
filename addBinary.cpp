class Solution {
public:
    string addB(string s1, string s2){
        int n1 = s1.size();
        int n2 = s2.size();
        int i = 0;
        int num= 0;
        int carry = 0;
        vector<int>temp;


        while (i < n1 || i < n2 || carry > 0) {
            int a1 = (i < n1) ? (s1[i] - '0') : 0;  
            int a2 = (i < n2) ? (s2[i] - '0') : 0;  

            int sum = a1 + a2 + carry;   
            temp.push_back(sum % 2);    
            carry = sum / 2;         

            i++;
        }



        // while (n1 > 0 && n2 > 0){
        //     int a1 = s1[i] - '0';
        //     int a2 = s2[i] - '0';
        //     int a = a1+a2;
        //     a += carry;
        //     if (a == 0){
        //         temp.push_back(0);
        //         carry = 0;
        //     }
        //     else if (a == 1){
        //         temp.push_back(1);
        //         carry = 0;
        //     }
        //     else if (a == 2){
        //         temp.push_back(0);
        //         carry = 1;
        //     }
        //     i++;
        //     n1--;
        //     n2--;
        // }
        // while (n1 > 0){
        //     int a = s1[i] - '0'; 
        //     a += carry;

        //     if (a == 0){
        //         temp.push_back(0);
        //         carry = 0;
        //     }
        //     else if (a == 1){
        //         temp.push_back(1);
        //         carry = 0;
        //     }
        //     else if (a == 2){
        //         temp.push_back(0);
        //         carry = 1;
        //     }
        //     n1--;
        //     i++;
        // }
        // while (n2 > 0){
        //     int a = s2[i] - '0'; 
        //     a += carry;

        //     if (a == 0){
        //         temp.push_back(0);
        //         carry = 0;
        //     }
        //     else if (a == 1){
        //         temp.push_back(1);
        //         carry = 0;
        //     }
        //     else if (a == 2){
        //         temp.push_back(0);
        //         carry = 1;
        //     }
        //     n2--;
        //     i++;
        // }

        if (carry > 0) temp.push_back(carry);
        reverse(temp.begin(), temp.end());
        string final_ans = "";

        for (int j = 0; j<temp.size();j++){
            final_ans += char('0' + temp[j]);
        }

        return final_ans;

    }
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string ans = addB(a, b);

        return ans;
        
    }
};