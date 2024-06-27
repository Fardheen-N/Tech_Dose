class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int> mp;
        for(auto i:edges){
            mp[i[0]]++;
            mp[i[1]]++;
        }
        for(auto i:mp){
            if(mp[i.first]>1) return i.first;
        }
        return 0;
    }
};