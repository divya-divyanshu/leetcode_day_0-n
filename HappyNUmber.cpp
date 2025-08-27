class Solution {
public:

    int happ(int n ){
        int sum = 0;
        while (n > 0){
            int a = n%10;
            n = n / 10;
            sum += a*a;
        }

        return sum;
    }
    
    
    bool isHappy(int n) {

        vector<int> happy;
        int ans = n;

        // if (ans == 1) return true;

        while (ans != 1){
            for (int i = 0; i < happy.size(); i++) {
                if (happy[i] == ans) {
                    return false;
                }
            }

        happy.push_back(ans);

        ans = happ(ans);
        }


        return true;
        
    }
};