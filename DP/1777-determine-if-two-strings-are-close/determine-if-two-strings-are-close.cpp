class Solution {
        int Freq1[26]{};  
        int Freq2[26]{};  
public:
    bool closeStrings(string &word1,string &word2){
        int n = word1.size();
        if(n != word2.size()) return false;

        for(int i=0;i<n;i++){
            Freq1[word1[i]-'a']++;
            Freq2[word2[i]-'a']++;
        }

        unordered_map<int,int> Hash;
        
        for(int i=0;i<26;i++){
            if((Freq1[i]>0) ^ (Freq2[i]>0))return false;
        }
        sort(Freq1 ,Freq1+26);
        sort(Freq2 ,Freq2+26);
        
        for(int i=0;i<26;i++){
            if(Freq1[i]!=Freq2[i]) return false;
        }

        return true;
    }
};