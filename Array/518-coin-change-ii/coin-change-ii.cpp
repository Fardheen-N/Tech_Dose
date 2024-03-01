class Solution {
public:

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1, -1));
        return solve(0,amount,coins,dp);
    }

    int solve(int ind,int amount,vector<int>& coins,vector<vector<int>>& dp) {
        if(ind == coins.size() || amount < 0) return 0;
        if(amount == 0) return 1;
        if(dp[ind][amount] != -1) return dp[ind][amount];

        int notTake = solve(ind+1,amount,coins,dp);
        int take = solve(ind,amount-coins[ind],coins,dp);

        return dp[ind][amount] = take + notTake;
    }
};