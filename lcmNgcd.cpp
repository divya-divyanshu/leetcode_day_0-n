class Solution {
  public:
    vector<int> lcmAndGcd(int a, int b) {
        int gcd = 1;
        int mini = min(a, b);
        while ( mini > 1){
            if (a % mini == 0 && b % mini == 0){
                gcd = mini;
                break;
            }
            else mini--;
        }
        int lcm = (a*b) / gcd;
        
        return {lcm, gcd};
    }
};