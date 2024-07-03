class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int par = nums.size();
        if(par<=4) return 0;
        return min({nums[par-2]-nums[2],nums[par-1]-nums[3],nums[par-3]-nums[1],nums[par-4]-nums[0]});   
    }
};

// 3 15 20 100 110