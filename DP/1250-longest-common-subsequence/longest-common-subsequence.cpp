class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n =text1.size();
        int m =text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int i=n;i>=0;i--) dp[i][m]=0;
        for(int j=m;j>=0;j--) dp[n][j]=0;

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(text1[i]==text2[j]) dp[i][j]=1+dp[i+1][j+1]; 
                else dp[i][j]=max(dp[i+1][j],dp[i][j+1]); 
            }
        }
        return dp[0][0];
    }
    // int solve(string s1,string s2,int i,int j,vector<vector<int>>&dp){
    //     if(i==s1.size()||j==s2.size()) return 0;
        
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s1[i]==s2[j])
    //     return dp[i][j]=1+solve(s1,s2,i+1,j+1,dp); 
        
    //     return dp[i][j]=max(solve(s1,s2,i+1,j,dp),solve(s1,s2,i,j+1,dp));  
    // }
};