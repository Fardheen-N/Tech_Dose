class Solution {
public:
    int minOperations(vector<string>& logs) {
        int stp = 0;
        for(auto i:logs){
            if(i[1]=='.'){
                if(stp!=0)stp--;
                else continue;
            }else if(i[0]=='.' &&i[1]=='/'){
                continue;
            }else{
                stp++;
            }
        }
        return stp;
    }
};