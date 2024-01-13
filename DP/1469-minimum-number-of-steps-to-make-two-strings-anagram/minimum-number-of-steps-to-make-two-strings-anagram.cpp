class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int> mp1,mp2;
        for(auto i:s) mp1[i]++;
        for(auto i:t) mp2[i]++;
        
        int ex = 0;
        int dif = 0;

        for(auto i:mp1){
            if(i.second-mp2[i.first]<0) {
                dif += abs(i.second-mp2[i.first]);
            }else{
                ex += i.second-mp2[i.first];
            }
        }
        for(auto i:mp2){
            if(mp1[i.first]==0) {
                dif += i.second;
            }
        }
        return min(ex,dif)+abs(ex-dif);
    }
};