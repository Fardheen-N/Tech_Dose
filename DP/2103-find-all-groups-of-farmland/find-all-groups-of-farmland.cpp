class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        queue<pair<int,int>> q;
        vector<vector<int>> res;
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                if(land[r][c]==1 && !vis[r][c]){
                    q.push({r,c});
                    int i=r,j=c;
                    while(!q.empty()){
                    int size = q.size();
                        while(size--){
                            i=q.front().first;
                            j=q.front().second;
                            q.pop();
                            if(i+1<n && !vis[i+1][j] && land[i+1][j]==1){ q.push({i+1,j}); vis[i+1][j]=1; }
                            if(j+1<m && !vis[i][j+1] && land[i][j+1]==1){ q.push({i,j+1}); vis[i][j+1]=1; } 
                        }
                    }
                    res.push_back({r,c,i,j});
                }
            }
        }
        return res;    
    }
};