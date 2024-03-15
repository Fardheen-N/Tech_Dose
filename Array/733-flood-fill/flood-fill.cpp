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
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        queue<pair<int,int>> q;
        q.push({sr,sc});

        VVI vis(n,VI(m,0));
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            int dx[]={-1,1,0,0};
            int dy[]={0,0,-1,1};

            for(int k=0;k<4;k++){
                int ni = i+dx[k];
                int nj = j+dy[k];
                if(ni>=0 && ni<n && nj>=0 && nj<m && image[ni][nj]==image[i][j] && vis[ni][nj]!=1){
                    q.push({ni,nj});
                    vis[ni][nj]=1;
                }
            }
            image[i][j]=color;
        }
        return image;
    }
};