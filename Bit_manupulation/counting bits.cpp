class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> rec(n+1,0);
        for(int i = 1;i<=n;i++){
            for(int j=0;j<32;j++){
                rec[i]+=(i>>j&1);
            }
        }
        return rec;
    }
};
