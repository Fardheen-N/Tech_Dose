class Solution {
public:
    int minimumPushes(string word) {
        vector<int> mp(27,0);
        int res = 0;
        for(int i=0;i<word.size();i++) mp[word[i]-'a']++; 
        sort(mp.begin(),mp.end(),greater<int>());
        for(int i=0;i<27;i++){
            res+=(mp[i]*((i/8)+1));
        }
        return res;
    }
};