class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int res  = 0;
        int size = tickets.size();
        int j =0;
        for(auto i:tickets){
            res += min(i,tickets[k]);
            if(k<j && tickets[j]>=tickets[k]) res--; 
            j++;
        }
        return res;
    }
};