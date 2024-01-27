class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans = 0;
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j]==1) {adj[i].push_back(j);adj[j].push_back(i);}
            }
        }
        // for(auto i:adj){
        //     for(auto j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                ans++;
                bfs(adj,vis,i);
                // cout<<i<<" ";
            }
        }
        return ans;
    }
    void bfs(vector<vector<int>> &adj,vector<int> &vis,int i){
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int row = q.front();q.pop();
                vis[row]=1;
                for(int j=0;j<adj[row].size();j++){
                   if(vis[adj[row][j]]==0){
                       q.push(adj[row][j]);
                   }
                }
            }
        }
    }
};