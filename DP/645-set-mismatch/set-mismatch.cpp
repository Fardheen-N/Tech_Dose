class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int ex = 0,size,sum =0;
        size = nums.size();
        map<int,int> mp;
        for(auto i:nums){
            mp[i]++;
            sum+=i;
            if(mp[i]==2) ex = i;
        }
        sum-=ex;
        int miss = ((size*(size+1))/2)-sum;
        return {ex,miss};
    }
};