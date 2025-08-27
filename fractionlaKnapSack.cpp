class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<pair<double, int>>prr;
        for(int i = 0; i < val.size(); i++){
            prr.push_back({(double)val[i]/(double)wt[i], i});
        }
        sort(prr.begin(), prr.end());
        double maxi = 0;
        
        for(int  i =n-1; i>=0;i--){
            if(capacity - wt[prr[i].second] >=0 ){
                maxi += (double)(prr[i].first*wt[prr[i].second]);
                capacity -=  wt[prr[i].second];
            }
            else{
                maxi +=  ((double)capacity/(double)wt[prr[i].second]) * (double)val[prr[i].second];
                capacity=0;
            }
        }
        
        return maxi;
        
    }
};