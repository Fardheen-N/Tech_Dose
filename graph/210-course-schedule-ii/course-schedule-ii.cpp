class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> res;
        vector<int> in(numCourses);
        for(auto i:prerequisites){
            adj[i[1]].push_back(i[0]);
            in[i[0]]++;
        }
        queue<int> q;
        int cnt =0;
        for(int i=0;i<numCourses;i++) if(in[i]==0) q.push(i);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int node = q.front();q.pop();
                res.push_back(node);
                for(auto i:adj[node]){
                    in[i]--;
                    if(in[i]==0) q.push(i);
                }
            }
        }
        if(res.size()==numCourses) return res;
        return {};
    }
};