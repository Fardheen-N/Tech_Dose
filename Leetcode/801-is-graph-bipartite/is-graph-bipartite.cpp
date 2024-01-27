class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(),-1);
        queue<int> q;
        int mask =0;
        for(int node = 0;node<graph.size();node++){
            if(vis[node]==-1){
                q.push(node);
                vis[node]=mask;
                while(!q.empty()){
                    int size = q.size();
                    while(size--){
                        int i = q.front();q.pop();
                        for(int j=0;j<graph[i].size();j++){
                            if(vis[graph[i][j]]==mask) return 0;
                            if(vis[graph[i][j]]==-1){
                                q.push(graph[i][j]);
                                vis[graph[i][j]]=!mask;
                            }  
                        }
                    }
                    mask = !mask;
                }
            }
            
        }

        return 1;
    }
};