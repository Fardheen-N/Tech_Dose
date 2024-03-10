class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,bool> mp;
        vector<int> res;
        for(auto i:nums1){
            mp[i]=1;
        }
        for(auto i:nums2){
            if(mp[i]==1){
                res.push_back(i);
                mp[i]=0;
            }
        }
        return res;
    }
};