class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> mp,freq;
        for(auto i:arr){
            mp[i]++;
        }
        for(auto i:mp){
            freq[i.second]++;
        }
        for(auto i:freq){
            if(i.second>1) return false;
        }
        return true;
    }
};