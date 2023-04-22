class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i=0;i<32;i++){
            int on = 0;
            for(int j=0;j<nums.size();j++){
                if(nums[j]&(1<<i)) on++;
            }
            if(on%3) res|=(1<<i);
        }
        return res;
    }
};
