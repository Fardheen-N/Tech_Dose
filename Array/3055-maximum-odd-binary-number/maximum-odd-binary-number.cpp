class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt = 0;
        for(auto i:s){
            if(i=='1') cnt++;
        }
        for(int i=0;i<s.size();i++){
            s[i]='0';
        }
        s[s.size()-1]='1';
        cnt--;
        int i = 0;
        while(cnt--){
            s[i++]='1';
        }
        return s;
    }
};