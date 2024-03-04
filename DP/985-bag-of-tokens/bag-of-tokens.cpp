typedef long long LL;
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define LB lower_bound
#define UB upper_bound
#define SZ(x) ((int)x.size())
#define LEN(x) ((int)x.length())
#define ALL(x) begin(x), end(x)
#define REV(x) reverse(x.begin(), x.end());
#define trav(a, x) for (auto& a : x)
typedef pair<LL, LL> PL;
typedef vector<LL> VL;
typedef vector<PL> VPL;
typedef vector<VL> VVL;
typedef vector<VVL> VVVL;
typedef vector<VVVL> VVVVL;
typedef vector<string> VS;
typedef pair<int, int> PI;
typedef vector<int> VI;
typedef vector<PI> VPI;
typedef vector<vector<int>> VVI;
typedef vector<vector<PI>> VVPI;
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define FOR(i, n) for (int i = 0; i < n; i++) 
#define FOR1(i, n) for (int i = 1; i <= n; i++) 
#define SORT(x) sort(x.begin(), x.end())
#define RSORT(x) sort(x.rbegin(), x.rend())
#define SUM(x) accumulate(x.begin(), x.end(), 0LL)
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        SORT(tokens);
        int n = tokens.size();
        VVI dp(n,VI(n,-1));
        return solve(tokens,power,0,0,n-1,dp);
    }
    int solve(vector<int>& tokens,int power,int score,int i,int j,VVI &dp){
        if(i>j) return score;
        if(dp[i][j]!=-1) return dp[i][j];

        int face_up = 0,face_down = 0,five_star=0;
        if(power>=tokens[i]) face_up=solve(tokens,power-tokens[i],score+1,i+1,j,dp);
        if(score>0) face_down=solve(tokens,power+tokens[j],score-1,i,j-1,dp);
        five_star = solve(tokens,power,score,i,j-1,dp);

        return dp[i][j]=max({face_up,face_down,five_star});
    }
};