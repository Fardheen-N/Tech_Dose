class Solution {
public:
    set<int>prime{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    int maximumPrimeDifference(vector<int>& nums) {
        int ft = -1;
        int res = 0;
        for(int i=0;i<nums.size();i++){
            if(prime.find(nums[i])!=prime.end()){
                if(ft==-1) ft = i;
                else{
                    res = max(i-ft,res);
                }
            }
        }
        return res;
    }
};