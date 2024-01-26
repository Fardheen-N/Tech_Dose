class Solution {
public:
    int MOD = 1e9+7;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return solve(m,n,startRow,startColumn,maxMove,dp)%MOD;
    }
    int solve(int m,int n,int i,int j,int mm,vector<vector<vector<int>>> &dp){
        if(i<0||i>=m||j<0||j>=n) return 1;
        if(mm==0) return 0;
        if(dp[i][j][mm]!=-1) return dp[i][j][mm];
        long long res = 0;
        // res=(res+solve(m,n,i+1,j,mm,dp))%MOD;
        // res=(res+solve(m,n,i,j+1,mm,dp))%MOD;
        // res=(res+solve(m,n,i-1,j,mm,dp))%MOD;
        // res=(res+solve(m,n,i,j-1,mm,dp))%MOD;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        for(int k = 0;k<4;k++){
            int new_i = i+delrow[k];
            int new_j = j+delcol[k];

            res += solve(m,n,new_i,new_j,mm-1,dp);
            res %= MOD;
        }
        
        return dp[i][j][mm]=res;
    }
};