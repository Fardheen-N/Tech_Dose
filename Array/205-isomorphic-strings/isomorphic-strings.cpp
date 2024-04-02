class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mp,mp2;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(mp[s[i]]==NULL && mp2[t[i]]==NULL) {mp[s[i]]=t[i];mp2[t[i]]=s[i];}
            else if(mp[s[i]]==t[i]) continue;
            else return 0;
        }
        return true;
    }
};