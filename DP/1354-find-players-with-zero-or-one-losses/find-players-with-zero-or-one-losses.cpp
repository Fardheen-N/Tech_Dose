class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,pair<int,int>> mp;
        for(auto i: matches){
            mp[i[0]].first++;
            mp[i[1]].second++;
        }
        vector<vector<int>> res(2);
        for(auto i:mp){
            if(i.second.second==0) res[0].push_back(i.first);
            if(i.second.second==1) res[1].push_back(i.first);
        }
        return res;
    }
};