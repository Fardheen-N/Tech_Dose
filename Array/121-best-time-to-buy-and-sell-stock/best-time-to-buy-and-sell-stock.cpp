class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prev = prices[0];
        int res = 0;
        for(int i=0;i<prices.size();i++){
            res = max(res,prices[i]-prev);
            prev = min(prev,prices[i]);
            // cout<<prev<<" "<<res<<endl;
        }
        return res;
    }
};