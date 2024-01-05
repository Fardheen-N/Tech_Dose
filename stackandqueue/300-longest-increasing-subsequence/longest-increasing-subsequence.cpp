class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(nums,-1,0,dp);
    }
    int solve(vector<int>& nums,int prev,int i,vector<vector<int>> &dp){
        // base case
        if(i==nums.size())
        return 0;

        //memoization
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];

        //recursive logic
        int notTake = solve(nums,prev,i+1,dp);
        int take =0;
        if(prev ==-1||nums[prev]<nums[i])
            take = 1+solve(nums,i,i+1,dp);
        return dp[i][prev+1]=max(take,notTake);
    }
};