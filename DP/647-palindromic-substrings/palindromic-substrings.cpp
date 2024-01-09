class Solution {
public:
    int countSubstrings(string s) {
        int res =0;
        int n =s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        for(int i=0;s[i];i++){
            res+=solve(s,i,1,dp);
        }
        return res;
    }
    int solve(string s,int i,int j,vector<vector<int>>&dp){
        if(i+j-1==s.size()) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        string str = s.substr(i,j);
        int isPal = isPalin(str);
        return dp[i][j]=isPal+solve(s,i,j+1,dp);
    }
    int isPalin(string s){
        string rev = s;
        reverse(s.begin(),s.end());
        if(s==rev) return 1;
        return 0;
    }
};