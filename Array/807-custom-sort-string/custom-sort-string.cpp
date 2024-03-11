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
    string customSortString(string order, string s) {
        vector<pair<int,char>> ss;
        map<char,int> mp;
        int size = order.size();
        for(int i=0;i<size;i++){
            mp[order[i]]=i+1;
        }
        // for(auto i:mp) cout<<i.first<<":"<<i.second<<endl;
        for(auto i:s){
            if(mp[i]!=0){
                ss.PB({mp[i],i});
            }else{
                ss.PB({size+1,i});
            }
        }
        SORT(ss);
        // for(auto i:ss) cout<<i.first<<":"<<i.second<<endl;
        string res = "";
        for(auto i:ss){
            res+=i.second;
        }
        return res;
    }
};