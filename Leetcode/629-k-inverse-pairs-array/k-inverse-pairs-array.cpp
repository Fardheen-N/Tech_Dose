class Solution {
public:
    vector<vector<int>> dp;
    int MOD =1e9+7;
    int kInversePairs(int n, int k) {
        dp=vector<vector<int>>(n+1,vector<int>(k+1,-1));
        return solve(n,k);
    }
    int solve(int n,int k){
        if(k==0) return 1;
        if(n==0) return 0;
        
        if(dp[n][k]!=-1) return dp[n][k];

        int count = 0;
        for(int i=0;i<=min(k,n-1);i++){
            count = (count+solve(n-1,k-i))%MOD;
        }
        return dp[n][k]=count;
    }
};