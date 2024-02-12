class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> mp;
        int st = 1;
        if(s.size()<10) return {};
        mp[s.substr(0,10)]++;
        for(int r = 10;r<s.size();r++){
            mp[s.substr(st,10)]++;
            st++;
        }
        vector<string> res;
        for(auto i:mp){
            if(i.second>1) res.push_back(i.first);
        }
        return res;
    }
};