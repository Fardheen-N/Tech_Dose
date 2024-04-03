class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int n = 0,m = 0;
    bool isOk(int i,int j){
        if(i<0 || i>=n) return false;
        if(j<0 || j>=m) return false;
        return true;
    }
    bool exist(vector<vector<char>>& board, string word) {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); 
        cout.tie(NULL);
        n = board.size();
        m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        bool res=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                vis[i][j]=1;
                if(check(i,j,board,word,1,vis)) return true;
                vis[i][j]=0;
                }
            }
        }
        return false;
    }
    bool check(int i,int j,vector<vector<char>>& board, string word,int k,vector<vector<int>> &vis){
        if(k==word.size()) {return true;}
        for(int p=0;p<4;p++){
            int nx = i+dx[p];
            int ny = j+dy[p];
            if(isOk(nx,ny) && vis[nx][ny]!=1){
                vis[nx][ny]=1;
                // cout<<nx<<" "<<ny<<" = "<<k<<endl;
                if(board[nx][ny]==word[k] && check(nx,ny,board,word,k+1,vis)) return true;
                vis[nx][ny]=0;
            }
        }
        return false;
    }
};