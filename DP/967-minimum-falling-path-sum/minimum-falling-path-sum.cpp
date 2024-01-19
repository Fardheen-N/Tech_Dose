class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int res = INT_MAX,n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));

        for(int i=0;i<n;i++){
            dp[0][i]=matrix[0][i];
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int d = matrix[i][j]+dp[i-1][j];
                int dl = (j-1>=0)?matrix[i][j]+dp[i-1][j-1]:INT_MAX;
                int dr = (j+1<matrix.size())?matrix[i][j]+dp[i-1][j+1]:INT_MAX;  
                dp[i][j]=min({d,dl,dr});  
            }
        }
        for(int i=0;i<n;i++) res=min(res,dp[n-1][i]);
        return res;
    }
    //TLE [memoization]
    int solve( vector<vector<int>> &dp,vector<vector<int>>& matrix,int i,int j){
        if(i==matrix.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int fallDown = matrix[i][j]+solve(dp,matrix,i+1,j);
        int fallLeft = (j-1>=0)?matrix[i][j]+solve(dp,matrix,i+1,j-1):INT_MAX;
        int fallRight = (j+1<matrix.size())?matrix[i][j]+solve(dp,matrix,i+1,j+1):INT_MAX;

        return dp[i][j]=min({fallDown,fallLeft,fallRight});
    }
};