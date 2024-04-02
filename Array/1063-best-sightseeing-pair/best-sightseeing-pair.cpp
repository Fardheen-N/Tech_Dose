class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int prev = 0,ans = 0;
        for(int i=0;i<values.size();i++){
            ans = max(prev+values[i]-i,ans);
            prev = max(values[i]+i,prev);
        }
        return ans;
    }
};