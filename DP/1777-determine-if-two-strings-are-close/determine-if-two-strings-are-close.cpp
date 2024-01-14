class Solution {
public:
    bool closeStrings(string word1, string word2) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n=word1.size();
        int m=word2.size();
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        if(n!=m) return false;
        for(int i=0;i<n;i++) freq1[word1[i]-97]++;
        for(int i=0;i<m;i++) freq2[word2[i]-97]++;
        for(int i=0;i<26;i++) if((freq1[i]==0 && freq2[i]!=0) || (freq1[i]==0 && freq2[i]!=0) ) return false;
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        return freq1==freq2;

    }
};