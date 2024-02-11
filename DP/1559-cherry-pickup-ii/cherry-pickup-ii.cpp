class Solution {
public:
    int dp[71][71][71];
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return solve(grid,0,0,grid[0].size()-1);
    }
    int solve(vector<vector<int>>& grid,int i,int j1,int j2){
        if(i==grid.size()||j1==grid[0].size()||j1<0||j2==grid[0].size()||j2<0){
            return 0;
        }
        if(dp[i][j1][j2]!=-1){
            return dp[i][j1][j2];
        }

        if(j1==j2) dp[i][j1][j2]=grid[i][j1];
        else dp[i][j1][j2] = grid[i][j1]+grid[i][j2];

        int res = dp[i][j1][j2];
        for(int r=-1;r<2;r++){
            int nj1 = j1+r;
            for(int c = -1;c<2;c++){
                int nj2 = j2+c;
                res= max(solve(grid,i+1,nj1,nj2)+dp[i][j1][j2],res);
            }
        }
        return dp[i][j1][j2]=res;
    }
};