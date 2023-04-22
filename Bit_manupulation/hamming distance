class Solution {
public:
    int hammingDistance(int x, int y) {
        int carry = x^y;
        int cnt =0;
        for(int i=0;i<32;i++){
            cnt+=(carry>>i&1);
        }
        return cnt;
    }
};
