class Solution {
public:
    string frequencySort(string s) {
        unordered_map<int,int> mp;
        for(auto i:s){
            mp[i]++;
        }
        vector<pair<int,char>> vec;
        for(auto i:s){
            vec.push_back({mp[i],i});
        }
        sort(vec.begin(),vec.end(),greater<pair<int,char>>());
        string res="";
        for(auto i:vec){
            res+=i.second;
        }
        return res;
    }
};