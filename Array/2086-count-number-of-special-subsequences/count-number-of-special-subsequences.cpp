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
#define MOD 1000000007

class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        int res =0;
        VVI dp(nums.size(),VI(4,-1));
        return solve(nums,-1,0,dp);
    }
    int solve(VI &nums,int prev,int i,VVI &dp){
        if(i==nums.size()) return 0;
        
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int pick = 0;
        if(nums[i]==2 && (prev==2 || prev == 1)) pick=1;
        if(prev == nums[i]-1 || prev == nums[i]) pick+=solve(nums,nums[i],i+1,dp);
        int notPick = solve(nums,prev,i+1,dp);

        return dp[i][prev+1]=(pick+notPick)%MOD;
    }
};