class Solution {
public:
    bool closeStrings(string word1, string word2) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
         map<char,int> mp;
        vector<pair<int,char>> v1,v2;
        for(auto i:word1) mp[i]++;
        for(auto i:mp) v1.push_back({i.second,i.first});
        mp.clear();
        for(auto i:word2) mp[i]++;
        for(auto i:mp) v2.push_back({i.second,i.first});

        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());

        if(v1.size()!=v2.size()) return 0;
        for(int i=0;i<v1.size();i++){
            if(v1[i].first!=v2[i].first||mp[v1[i].second]==0) return 0;
        }
        return 1;

    }
};