class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        vector<vector<int>> mp(bombs.size());
        int n = bombs.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                long x = (bombs[i][0]-bombs[j][0]);
                long y = (bombs[i][1]-bombs[j][1]);
                long r = bombs[i][2];
                // double dis = x*x+y*y;
                if(x*x+y*y<=r*r) mp[i].push_back(j);
            }
        }
        for(auto i:mp){
            for(auto j:i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        int ans =1;
        // vector<int> vis(n,0);
        queue<int> q;
        for(int i=0;i<n;i++){
            vector<int> vis(n,0);
            if(vis[i]==0){
                int bb = 1;
                q.push(i);
                vis[i]=1;
                while(!q.empty()){
                    int size=q.size();
                    while(size--){
                        int po = q.front();q.pop();
                        for(int j=0;j<mp[po].size();j++){
                            if(vis[mp[po][j]]==0){
                                vis[mp[po][j]]=1;
                                q.push(mp[po][j]);
                                bb++;
                            }
                        }
                    }
                }
                ans = max(ans,bb);
            }
        }
        return ans;
    }
};