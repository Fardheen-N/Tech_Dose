class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int l = 0,r=0;
        int n = grumpy.size();
        int pro = 0;
        for(int i=0;i<n;i++) if(grumpy[i]==0)pro+=customers[i];
        while(r-l<minutes){
            if(grumpy[r]==1){
                grumpy[r]=2;
                pro+=customers[r];
            }
            r++;
        }
        
        int maxi = pro;
        while(r<n){
            if(grumpy[l]==2){
                pro-=customers[l];
            }
            if(grumpy[r]==1){
                grumpy[r]=2;
                pro+=customers[r];
            }
            maxi = max(pro,maxi);
            l++;r++;
        }
        return maxi;
    }
};
// 1 0 1 2 1 1 7 5
// 0 1 0 1 0 1 0 1
