class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!='0'&&vis[i][j]!=1){
                    ans++;
                    bfs(grid,vis,i,j);
                }
            }
        }
        return ans;
    }
    void bfs(vector<vector<char>> &grid,vector<vector<int>> &vis,int i,int j){
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        q.push({i,j});
        vis[i][j]=1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                pair<int,int> pr = q.front();q.pop();
                int row = pr.first;
                int col = pr.second;
                int row_del[] = {-1,1,0,0};
                int col_del[] = {0,0,-1,1};
                for(int k=0;k<4;k++){
                    int new_i = row+row_del[k];
                    int new_j = col+col_del[k];
                    if(new_i>=0 && new_j>=0 && new_i<n && new_j<m && grid[new_i][new_j]!='0' && vis[new_i][new_j]!=1){
                        q.push({new_i,new_j});
                        vis[new_i][new_j]=1;
                    }
                }
            }
        }
    }
};