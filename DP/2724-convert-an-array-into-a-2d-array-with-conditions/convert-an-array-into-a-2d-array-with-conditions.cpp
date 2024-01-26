class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int> freq;
        queue<int> q;
        for(auto i:nums) freq[i]++;
        vector<vector<int>> res;
        for(auto i:freq) q.push(i.first);
        while(!q.empty()){
            int size=q.size();vector<int> t;
            while(size--){
            t.push_back(q.front()); 
            if(--freq[q.front()]>0) q.push(q.front());
            q.pop();
            }
            res.push_back(t);
        }
        return res;
    }
};