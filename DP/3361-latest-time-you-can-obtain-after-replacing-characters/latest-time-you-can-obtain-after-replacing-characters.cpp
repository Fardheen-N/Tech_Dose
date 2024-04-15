class Solution {
public:
    string findLatestTime(string s) {
        for(int i=0;i<s.size();i++){
            if(s[i]=='?'){
                // cout<<i<<":";
                switch(i){
                    case 0:
                    if(s[1]!='1' && s[1]!='?' && s[1]!='0') s[i]='0';
                    else s[i]='1';
                    // cout<<'0'<<endl;
                    break;
                    case 1:
                    if(s[i-1]=='1') s[i]='1';
                    else s[i]='9';
                    // cout<<'1'<<endl;
                    break;
                    case 3:
                    s[i]='5';
                    break;
                    case 4:
                    s[i]='9';
                    break;
                }
            }
        }
        return s;
    }
};