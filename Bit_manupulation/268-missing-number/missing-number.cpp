class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int maxi = 0;
        bool zero = 0;
        for(auto i:nums){
            sum+=i;
            if(i==0) zero =1;
            maxi=max(maxi,i);
        }
        if(!zero) return 0;
        int n = maxi;
        int tot = ((n+1)*n)/2;
        return (tot-sum!=0)?(tot-sum):maxi+1;
    }
};