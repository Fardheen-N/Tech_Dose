class Solution {
public:
    int numTrees(int n) {
        int rec[n+1];
        rec[0]=1;
        rec[1]=1;
        for(int i=2;i<=n;i++){
            int sum = 0;
            for(int j=0;j<i;j++)
            sum+=rec[j]*rec[i-j-1];
            rec[i]=sum;
        }
        return rec[n];
    }
};
