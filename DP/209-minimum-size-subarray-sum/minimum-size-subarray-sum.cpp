class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, currSum = 0;
        int ans = INT_MAX;
        for(int r = 0; r < nums.size(); r++) {
            currSum += nums[r];
            while (currSum >= target){
                ans = min(ans, r-l+1);
                currSum -= nums[l];
                l++;
            }
        }
        return ans==INT_MAX?0:ans;   
    }
};