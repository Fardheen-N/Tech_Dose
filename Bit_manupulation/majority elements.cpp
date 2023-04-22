class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int size = nums.size();
       int ans =0;
       for(int i=0;i<32;i++){
           int on = 0;
           int mask = 1<<i;
           for(int j=0;j<size;j++){
               if(nums[j]&mask) on++;
           }
           if(on>(size/2)) ans|=mask;
       }
       return ans;
    }
};
