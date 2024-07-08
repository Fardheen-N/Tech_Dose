class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = 0;
        int rem = 0,bottle=numBottles;
        while(bottle){
            res+=bottle;
            int remi=((bottle+rem)%numExchange);
            bottle=((bottle+rem)/numExchange);
            rem=remi;
        }
        return res;
    }
};