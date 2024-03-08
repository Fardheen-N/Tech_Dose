class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> mp;
        int max =0;
        for(auto i:nums) {
            mp[i]++;
            if(max<mp[i])max=mp[i];
        }
        int res =0;
        for(auto i:mp){
            if(i.second==max) res+=i.second;
        }
        return res;
    }
};