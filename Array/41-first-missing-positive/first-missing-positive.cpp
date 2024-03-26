class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int,int> mp;
        for(auto i:nums) if(i>0) mp[i]++;
        int res = -1;
        int pass = 0;
        for(auto i:mp){
            if(pass+1!=i.first) return pass+1;
            else{
                pass++;
            }
        }
        return pass+1;
    }
};
