class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        stack<int> st;
        long long res=-1,sum=0;
        for(auto i:nums){
            sum+=i;
            if(i<sum-i) res=sum;
        }
        return res;
    }
};