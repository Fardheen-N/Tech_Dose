class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<int>res (n,0);
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int d1 = abs(i-j);
                int d2 = abs(x-i)+abs(y-j)+1;
                int d3 = abs(x-j)+abs(y-i)+1;
                res[min({d1,d2,d3})-1]+=2;
            }
        }
        return res;
    }
};